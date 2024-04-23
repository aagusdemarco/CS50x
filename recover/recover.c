#include <stdio.h>
#include <stdlib.h>
// Include stdint for uint8 type
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Verify correct usage
    if (argc != 2)
    {
        return 1;
    }

    // Open memory card
    FILE *card = fopen(argv[1], "r");

    // Create a buffer of 512 bytes for storing the jpegs
    uint8_t buffer[512];

    // Declare variables for status of search and counter
    int foundjpeg = 0;
    int counter = 0;

    // Declare variables for images found and its name
    char filename[8];
    FILE *image = NULL;

    // Loop through the memory card
    while (fread(buffer, 1, 512, card))
    {
        // Determine if a new jpeg is found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            foundjpeg = 1;
        }

        if (foundjpeg == 1)
        {
            // Determine if the image found is the first one
            if (counter != 0)
            {
                fclose(image);
            }

            // Create a file for the new image
            sprintf(filename, "%03i.jpg", counter);
            image = fopen(filename, "w");
            fwrite(buffer, 1, 512, image);
            foundjpeg = 0;
            counter++;
        }
        else if (counter != 0)
        {
            fwrite(buffer, 1, 512, image);
        }
    }

    // Close the opened files
    fclose(image);
    fclose(card);
}
