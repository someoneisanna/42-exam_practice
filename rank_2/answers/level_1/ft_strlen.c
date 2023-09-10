//#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
int main(void)
{
	char *str = "12345678901234567890";
	printf("%i", ft_strlen(str));
}
*/
