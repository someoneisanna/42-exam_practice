#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void error(char *msg, char *arg)
{
	for (int i = 0; msg[i]; i++)
		write(2, &msg[i], 1);
	if (arg)
	{
		for (int i = 0; arg[i]; i++)
			write(2, &arg[i], 1);
	}
	write(2, "\n", 1);
	exit (1);
}

int execute_cd(int index, char **av)
{
	if (!av[index + 1] || strcmp(av[index + 2], ";"))
		error("error: cd: bad arguments", NULL);
	if (chdir(av[2]) < 0)
		error("error: cd: cannot change directory to ", av[2]);
	return (index + 2);
}

int execute_cmd(int index, char **av, char **envp)
{
	(void)envp;
	printf("execute_cmd: %s\n", av[index]);
	return (index);
}

int main(int ac, char **av, char **envp)
{
	(void)envp;
	if (ac < 2)
		return (1);
	for (int i = 1; av[i]; i++)
	{
		if (!strcmp(av[i], "cd"))
			i = execute_cd(i, av);
		else if (!strcmp(av[i], ";"))
			continue;
		else if (!strcmp(av[i], "|"))
			i = execute_cmd(i, av, envp);
		else
			printf("%s\n", av[i]);
	}
}
