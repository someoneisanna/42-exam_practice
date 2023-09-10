#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
	{
		char *a = "MLKJIHGFEDCBA";
		char *b = "mlkjihgfedcba";
		char *c = "ZYXWVUTSRQPON";
		char *d = "zyxwvutsrqpon";
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'M')
				argv[1][i] = c[argv[1][i] - 65];
			else if (argv[1][i] >= 'N' && argv[1][i] <= 'Z')
				argv[1][i] = a[argv[1][i] - 78];
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'm')
				argv[1][i] = d[argv[1][i] - 97];
			else if (argv[1][i] >= 'n' && argv[1][i] <= 'z')
				argv[1][i] = b[argv[1][i] - 110];
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

/*
EASIER SOLUTION:

int main(void)
{
	int i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = 'Z' - argv[1][i] + 'A';
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = 'z' - argv[1][i] + 'a';
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
*/
