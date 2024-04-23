#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Verify correct usage
    if (argc != 2)
    {
        return 1;
    }

    // Open memory card
    FILE *card = fopen(argv[1], "r");

    // Loop through the memory card
    while(fread())
}
