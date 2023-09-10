#include <string.h> //size_t
//#include <stdio.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	while(s[i])
	{
		int j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

/*
int main(void)
{
	char *str = "hello there";
	char *reject = "rl";
	size_t len = strcspn(str, reject);
	size_t len_1 = ft_strcspn(str, reject);
	printf("%li, %li\n", len, len_1);
}
*/
