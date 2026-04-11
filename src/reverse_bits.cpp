#include <unistd.h>

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

//int main(void)
//{
//  unsigned char bits = reverse_bits(0b0100110);
//  return 0;
//}