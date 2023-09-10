#include <stdio.h>
#include <stdlib.h>

void pgcd(int a, int b)
{
	int i = 1;
	int r = 0;
	while(i < a && i < b)
	{
		if (a % i == 0 && b % i == 0)
			r = i;
		i++;
	}
	printf("%i", r);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		pgcd(a, b);
	}
	printf("\n");
}
