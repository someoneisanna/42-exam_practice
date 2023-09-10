#include <stdio.h>
#include <stdlib.h>

void ft_prime(int n)
{
	int i = 2;
	if (n == 1)
	{
		printf("1");
		return ;
	}
	while(n >= i)
	{
		if (n % i == 0)
		{
			printf("%i", i);
			if (n != i)
				printf("*");
			n /= i;
			i--;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_prime(atoi(argv[1]));
	printf("\n");
}
