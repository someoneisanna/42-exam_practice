#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	num_bytes = 8;
	int i = num_bytes - 1; //index of the last bit
	unsigned char 	bit;

	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}

/*
int main(void)
{
	print_bits(2);
}
*/
