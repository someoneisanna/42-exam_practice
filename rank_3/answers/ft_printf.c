#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *, ... );
int	ft_printf_s(char *s);
int	ft_printf_d(long n);
int	ft_printf_x(unsigned int n);

/*
int main(void)
{
	int a = INT_MAX;
	char *b = NULL;

	int c = ft_printf("int: %d, hex: %x, str: %s, perc: %%%%%%\n", a, a, b);
	int d = printf("int: %i, hex: %x, str: %s, perc: %%%%%%\n", a, a, b);

	printf("lengths: %i, %i\n", c, d);
}
*/

int ft_printf(const char *fmt, ... )
{
	int		i = 0;
	int		l = 0;
	va_list	ap;

	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != '\0')
		{
			i++;
			if (fmt[i] == 's')
				l += ft_printf_s(va_arg(ap, char *));
			if (fmt[i] == 'd')
				l += ft_printf_d(va_arg(ap, int));
			if (fmt[i] == 'x')
				l += ft_printf_x(va_arg(ap, unsigned int));
			if (fmt[i] == '%')
				l += write(1, &fmt[i], 1);
		}
		else
			l += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (l);
}

int	ft_printf_s(char *s)
{
	int i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf_d(long n)
{
	int l = 0;
	if (n < 0)
	{
		l += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		l += ft_printf_d(n / 10);
		l += ft_printf_d(n % 10);
	}
	else
	{
		n += '0';
		l += write(1, &n, 1);
	}
	return (l);
}

int	ft_printf_x(unsigned int n)
{
	int l = 0;
	char *hex = "0123456789abcdef";
	if (n >= 16)
	{
		l += ft_printf_x(n / 16);
		l += ft_printf_x(n % 16);
	}
	else
	{
		n = hex[n];
		l += write(1, &n, 1);
	}
	return (l);
}
