#include <stdio.h>
#include <stdlib.h>

int n_len(int n)
{
	int i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while(n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int nb)
{
	long n = nb;
	int len = n_len(n);
	char *r = (char *)malloc(sizeof(char) * len + 1);
	if(!r)
		return (NULL);
	r[len] = '\0';
	if (n == 0)
	{
		r[0] = '0';
		return (r);
	}
	if (n < 0)
	{
		r[0] = '-';
		n = -n;
	}
	while(n > 0)
	{
		r[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (r);
}

int main(void)
{
	char *a = ft_itoa(-10);
	printf("%s\n", a);
}
