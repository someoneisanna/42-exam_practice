#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int error(char *msg, char *arg)
{
	for (int i = 0; msg[i]; i++)
		write(2, &msg[i], 1);
	if (arg)
	{
		for (int i = 0; arg[i]; i++)
			write(2, &arg[i], 1);
	}
	write(2, "\n", 1);
	return (1);
}

int execute_cd(int n_args, char **args)
{
	if (n_args != 2)
		return (error("error: cd: bad arguments", NULL));
	if (chdir(args[1]) < 0)
		return (error("error: cd: cannot change directory to ", args[1]));
	return (0);
}

int execute_cmd(int end, char **args, char **envp)
{
	int fd[2];
	int exit_code;
	int has_pipe = 0;
	int pid;
	
	if (end == 0)
		return (1);
	if (args[end] && !strcmp(args[end], "|"))
		has_pipe = 1;
	if (has_pipe && pipe(fd) < 0)
		return (error("error: fatal", NULL));
	pid = fork();
	if (pid == 0)
	{
		args[end] = NULL;
		if (has_pipe && (dup2(fd[1], 1) < 0 || close(fd[0]) < 0 || close(fd[1]) < 0))
			return (error("error: fatal", NULL));
		execve(args[0], args, envp);
		return (error("error: cannot execute ", args[0]));
	}
	waitpid(pid, &exit_code, 0);
	if (has_pipe && (dup2(fd[0], 0) < 0 || close(fd[0]) < 0 || close(fd[1]) < 0))
		return (error("error: fatal", NULL));
	return (WEXITSTATUS(exit_code));
}

int main(int ac, char **av, char **envp)
{
	int i = 0;
	int start = 0;
	int exit_code = 0;

	if (ac < 2)
		return (1);
	while (av[i] && av[++i])
	{
		start = i;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (!strcmp(av[start], "cd"))
			exit_code = execute_cd(i - start, av + start);
		else
			exit_code = execute_cmd(i - start, av + start, envp);
	}
	return (exit_code);
}
