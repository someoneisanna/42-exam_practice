//#include <stdio.h>

char *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/*
int main(void)
{
	char *src = "hello there";
	char dst[100];
	ft_strcpy(dst, src);
	printf("dst: %s, src: %s", dst, src);
}
*/
