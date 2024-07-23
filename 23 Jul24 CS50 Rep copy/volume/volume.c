// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[44];
    fread(header, 1, HEADER_SIZE, input);
    fwrite(header, 1, HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file

    // Calculating the number of 2 byte sample sequences
    int16_t buffer = 0;
    int i = 0;
    while (fread(&buffer, 2, 1, input) != 0)
    {
        i++;
    }

    // Creating an array to copy said sample sequences
    int16_t sample_sequence[i];

    // Copying sample sequences
    fclose(input);
    input = fopen(argv[1], "r");
    fread(header, 1, HEADER_SIZE, input);
    fread(sample_sequence, 2, i, input);

    // "Factoring" sample sequences
    for (int j = 0; j < i; j++)
    {
        sample_sequence[j] *= factor;
    }

    // Writing sample sequences to output file
    fwrite(sample_sequence, 2, i, output);

    // Close files
    fclose(input);
    fclose(output);
}
