#include <stdio.h>

int max(int *tab, unsigned int len)
{
	int m;
	unsigned int i = 0;

	m = tab[i];
	while(i < len)
	{
		if (m < tab[i])
			m = tab[i];
		i++;
	}
	return (m);
}

/*
int main(void)
{
	int tab[5] = {1, 2, 30, 4, 5};
	printf("%i\n", tab[0]);
	int m = max(tab, 5);
	printf("%i\n", m);
}
*/
