#include <unistd.h>

int ft_dup(char *s, char c, int i)
{
	while (i > 0)
	{
		if (s[i - 1] == c)
			return (1);
		i--;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		while (argv[1][i])
		{
			int j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j] && ft_dup(argv[2], argv[1][i], j) == 0 && ft_dup(argv[1], argv[1][i], i) == 0)
					write(1, &argv[1][i], 1);
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
