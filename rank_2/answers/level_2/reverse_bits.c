//#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char r = 0;
	unsigned int n_bytes = 8;

	while(n_bytes > 0)
	{
		r = ((r << 1) | (octet & 1));
		octet = octet >> 1;
		n_bytes--;
	}
	return (r);
}

/*
int main(void)
{
	unsigned char c = '.';
	write(1, &c, 1);
	write(1, "\n", 1);
	c = reverse_bits(c);
	write(1, &c, 1);
	write(1, "\n", 1);
}
*/
// . (46 in ascii) becomes t (116 in ascii)
