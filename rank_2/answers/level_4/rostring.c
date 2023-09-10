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
		int n = ft_strcount(argv[1]);
		int i = 1;
		while (i < n)
		{
			ft_putstr(s[i]);
			ft_putstr(" ");
			free(s[i]);
			i++;
		}
		ft_putstr(s[0]);
		free(s[0]);
		free(s);
	}
	write(1, "\n", 1);
}
