#include <unistd.h>

void ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		char c = n + '0';
		write(1, &c, 1);
	}
}

int main(int argc, char **argv)
{
	(void)argv;
	int n = argc - 1;
	ft_putnbr(n);
	write(1, "\n", 1);
}
