#include <unistd.h>

int ft_dup(char *s, char c, int i)
{
	int j = 0;
	while (j < i)
	{
		if (s[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int k = 0;
	if (argc == 3)
	{
		while(argv[1][i])
			i++;
		while(argv[2][j])
		{
			argv[1][i] = argv[2][j];
			i++;
			j++;
		}
		while(k < i)
		{
			if (ft_dup(argv[1], argv[1][k], k) == 0)
				write(1, &argv[1][k], 1);
			k++;
		}
	}
	write(1, "\n", 1);
}
