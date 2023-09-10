#include <unistd.h>

int main(void)
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else
		{
			if (i % 3 == 0)
				write(1, "fizz", 4);
			else if (i % 5 == 0)
				write(1, "buzz", 4);
			else
			{
				char f = i / 10 + '0';
				char s = i % 10 + '0';
				if (i > 9)
					write(1, &f, 1);
				write(1, &s, 1);
			}
		}
		write(1, "\n", 1);
		i++;
	}
}
