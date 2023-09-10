#include <unistd.h>

int ft_atoi(char *s)
{
	int i = 0;
	int r = 0;
	while(s[i] != '\0')
	{
		r *= 10;
		r = r + s[i] - '0';
		i++;
	}
	return (r);
}

void print_hex(int n)
{
	char hex[] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex[n % 16], 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}
