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

int ft_atoi(char *str)
{
	int r = 0;
	int i = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r += (str[i] - '0');
		i++;
	}
	return (r);
}

int ft_isprime(int n)
{
	int i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int ft_prime_sum(int n)
{
	int i = 2;
	int s = 0;
	while (i <= n)
	{
		if (ft_isprime(i) == 1)
			s += i;
		i++;
	}
	return (s);
}

int main(int argc, char **argv)
{
	long n;
	int s;
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		if (n >= 0)
		{
			s = ft_prime_sum(n);
			ft_putnbr(s);
		}
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
