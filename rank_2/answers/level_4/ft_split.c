#include <stdlib.h>
#include <stdio.h>

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

int main(void)
{
	char *s = "this is a split example";
	char **words = ft_split(s);
	int count = ft_strcount(s);

	for(int i = 0; i < count; i++)
	{
		printf("%i: %s\n", i, words[i]);
		free(words[i]);
	}
	free(words);
}
