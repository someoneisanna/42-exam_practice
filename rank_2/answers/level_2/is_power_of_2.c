//#include <stdio.h>

//power of two: 2², 2³, ... , 2^n

int is_power_of_2(unsigned int n)
{
	unsigned int i = 1;
	while (i <= n)
	{
		if (i == n)
			return (1);
		i = i * 2;
	}
	return (0);
}

/*
int main(void)
{
	int a = 512;
	int b = is_power_of_2(a);
	printf("%i\n", b);
}
*/
