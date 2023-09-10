#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end)
{
	int n = start - end;
	if (n < 0)
		n *= -1;
	int size = n + 1;
	int *range = (int *)malloc(sizeof(int) * size);
	if (!range)
		return (NULL);
	int i = 0;
	while (i < size)
	{
		if (start <= end)
			range[i] = start + i;
		else
			range[i] = start - i;
		i++;
	}
	return (range);
}

/*
int main(void)
{
	int a = -1;
	int b = 3;
	int s = -(a - b) + 1;
	int *c = ft_range(a, b);
	for (int i = 0; i < s; i++)
		printf("%i\n", c[i]);
}
*/
