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

    int foundjpeg = 0;
    int counter = 0;
    char filename[8];
    FILE *image;

    // Loop through the memory card
    while(fread(buffer, 1, 512, card))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if ()
        }
    }
}
