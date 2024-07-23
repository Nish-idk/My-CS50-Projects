#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    // Ensuring only 2 command line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");

    // Ensuring no bogus name is inputted
    if (card == NULL)
    {
        printf("File not found.\n");
        return 1;
    }

    // Creating an array of pointers to point to 50 JPEGs
    FILE *JPEG_ptr[50];

    // Creating a string to store the 7 chars of each JPEG file's name
    char filename[8];

    BYTE buffer[512] = {0};

    int i = 0;
    int return_value = 1;

    // Finding the first JPEG
    while (!(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
             (buffer[3] & 0xf0) == 0xe0))
    {
        // buffer will store the very first block; fread will point to the second block
        return_value = fread(buffer, 512, 1, card);
    }

    while (return_value == 1)
    {
        i++;
        /* When the code reaches this stage, fread has read the very first header block, stored its
           contents in buffer, and now points to the second block of the first JPEG */
        sprintf(filename, "%03i.jpg", i - 1);
        JPEG_ptr[i - 1] = fopen(filename, "w");
        // Writing the contents of the header to the first JPEG
        fwrite(buffer, 512, 1, JPEG_ptr[i - 1]);

        return_value = fread(buffer, 512, 1, card);
        while (!(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
                 (buffer[3] & 0xf0) == 0xe0))
        {
            fwrite(buffer, 512, 1, JPEG_ptr[i - 1]);
            return_value = fread(buffer, 512, 1, card);
            if (return_value != 1)
            {
                break;
            }
        }
        // At this stage the next header has been found
        fclose(JPEG_ptr[i - 1]);
        printf("%s closed\n", filename);
    }

    // When the code reaches this point, the 50th JPEG has been written.
    fclose(card);
}
