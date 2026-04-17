#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i = 8;
    while (i--)
    {
        if (octet & 128)
            write(1, "1", 1);
        else
            write(1, "0", 1);

        octet <<= 1;
    }
}

/*
void print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit = 0; 

    while (i--) 
    {
        bit = (octet >> i & 1) + '0';
        write (1, &bit, 1);
    }
}
*/