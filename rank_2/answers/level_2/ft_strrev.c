//#include <stdio.h>

//why not a simpler way?
//because we cannot use malloc or return a new string. it should be the str from the parameter

char *ft_strrev(char *str)
{
	int len = 0;
	while(str[len])
		len++;
	int i = 0;
	char tmp;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}

/*
int main(void)
{
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	ft_strrev(str);
	printf("%s\n", str);
}
*/
