#include <unistd.h> //write
#include <stdio.h> //printf
#include <stdlib.h> //atoi

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[3]);
		int result;
		
		if (argv[2][0] == '+')
			result = a + b;
		else if (argv[2][0] == '-')
			result = a - b;
		else if (argv[2][0] == '*')
			result = a * b;
		else if (argv[2][0] == '/')
			result = a / b;
		else if (argv[2][0] == '%')
			result = a % b;
		printf("%i", result);
	}
	printf("\n");
}
