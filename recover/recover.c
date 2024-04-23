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

    // Loop through the memory card
    while(fread(buffer, 1, 512, card))
    {
        
    }
}
