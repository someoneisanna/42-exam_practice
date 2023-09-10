//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
int main(void)
{
	int a = 5;
	int b = 6;
	printf("a: %i, b: %i\n", a, b);
	ft_swap(&a, &b);
	printf("a: %i, b: %i\n", a, b);
}
*/
