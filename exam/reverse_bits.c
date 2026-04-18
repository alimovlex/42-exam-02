#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
    // 1. Swap nibbles (4-bit chunks) - Exactly what your swap_bits does
    octet = (octet << 4) | (octet >> 4);
    // 2. Swap 2-bit pairs within each nibble using mask 11001100 (0xCC) and 00110011 (0x33)
    octet = ((octet & 0xCC) >> 2) | ((octet & 0x33) << 2);
    // 3. Swap individual bits using mask 10101010 (0xAA) and 01010101 (0x55)
    octet = ((octet & 0xAA) >> 1) | ((octet & 0x55) << 1);

    return (octet);
}

/*
unsigned char	reverse_bits(unsigned char octet)
{
    int	i = 8, res = 0;

    while (i--)
    {
        // 1. Shift the result left to make room for the next bit
        res <<= 1;

        // 2. Take the rightmost bit of octet and add it to res
        res |= (octet & 1);

        // 3. Shift octet right to bring the next bit into position
        octet >>= 1;
    }
    return (res);
}


unsigned char		reverse_bits(unsigned char octet)
{
	unsigned char tmp;
	unsigned char res = 0;

	int i = 8;
	while (i--)
	{
		tmp = octet >> i;
		tmp = tmp << 7;
		tmp = tmp >> i;
		res = res + tmp;
	}
	return (res);
}
*/

//int main(void)
//{
//  unsigned char bits = reverse_bits(0b0100110);
//  return 0;
//}