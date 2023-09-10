#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	if (str_base < 2 || str_base > 16)
		return (0);
	int r = 0;
	int sg = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sg = -1;
		str++;
	}

	while (*str)
	{
		int d = 0;
		if (*str >= '0' && *str <= '9')
			d = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			d = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			d = *str - 'A' + 10;
		else
			break;
		if (d >= str_base)
			break;
		r = r * str_base + d;
		str++;
	}
	return (sg * r);
}

int main(void)
{
	char *str = "0123456789ffff";
	int a = ft_atoi_base(str, 16);
	int b = ft_atoi_base(str, 2);
	printf("%i\n", a);
	printf("%i\n", b);
}
