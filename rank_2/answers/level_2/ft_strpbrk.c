//#include <string.h>
//#include <stdio.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	while (s1[i])
	{
		int j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return ((char *)(s1 + i));
}

/*
int main(void)
{
	char *s1 = "hello there";
	char *s2 = "t";
	char *r = strpbrk(s1, s2);
	char *r2 = ft_strpbrk(s1, s2);
	printf("%s, %s\n", r, r2);
}
*/
