#include <stdlib.h>
#include <unistd.h>

int ft_delimiter(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int ft_strcount(char *s)
{
	int i = 0;
	int w = 0;
	while (s[i])
	{
		if (ft_delimiter(s[i]) == 0)
		{
			w++;
			while(s[i] && ft_delimiter(s[i]) == 0)
				i++;
		}
		else
			i++;
	}
	return (w);
}

char *ft_add_word(char *s)
{
	int i = 0;
	while(s[i] && ft_delimiter(s[i]) == 0)
		i++;
	char *w = (char *)malloc(sizeof(char) * (i + 1));
	if (!w)
		return (NULL);
	i = 0;
	while(s[i] && ft_delimiter(s[i]) == 0)
	{
		w[i] = s[i];
		i++;
	}
	w[i] = '\0';
	return (w);
}

char **ft_split(char *s)
{
	int i = 0;
	int j = 0;
	char **split = (char **)malloc(sizeof(char *) * (ft_strcount(s)) + 1);
	if (!split)
		return ('\0');
	while(s[i])
	{
		if (ft_delimiter(s[i]) == 0)
		{
			split[j] = ft_add_word(s + i);
			while (s[i] && ft_delimiter(s[i]) == 0)
				i++;
			j++;
		}
		else
			i++;
	}
	split[j] = 0;
	return (split);
}

void ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		char **s = ft_split(argv[1]);
		int n = ft_strcount(argv[1]) - 1;
		while (n >= 0)
		{
			ft_putstr(s[n]);
			if (n > 0)
				ft_putstr(" ");
			free(s[n]);
			n--;
		}
		free(s);
	}
	write(1, "\n", 1);
}

/* other solution:
int main(int argc, char **argv)
{
	int s;
	int e;
	int a;
	int i = 0;

	if (argc == 2)
	{
		while(argv[1][i])
			i++;
		while(i >= 0)
		{
			while(argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			e = i;
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			s = i + 1;
			a = s;
			while(s <= e)
			{
				write(1, &argv[1][s], 1);
				s++;
			}
			if (a != 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}
*/
