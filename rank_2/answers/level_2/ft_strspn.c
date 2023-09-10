#include <string.h> //left it open because of size_t
#include <stdio.h>

int ft_accept_found(const char *accept, char c)
{
	int i = 0;
	while (accept[i])
	{
		if (accept[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	while(s[i])
	{
		if (ft_accept_found(accept, s[i]) == 0)
			break;
		i++;
	}
	return (i);
}

/*
int main(void)
{
	char *s = "hello";
	char *accept = "he";
	size_t a = strspn(s, accept);
	size_t a1 = ft_strspn(s, accept);
	printf("%li, %li\n", a, a1);
}
*/
