#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int tmp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

/*
int main(void)
{
	int tab[10] = {1, 2, 3, 4, 89, 423, 3, 1, 6, 7};
	sort_int_tab(tab, 10);
	for(int i = 0; i < 10; i++)
		printf("%i\n", tab[i]);
}
*/
