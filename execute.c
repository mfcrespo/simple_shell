#include "simple_shell.h"

/**
 * execute - Forks a child process and executes a new process
 * @args: user input array arguments
 * Return:  0 or 1 according file program execution
 */
int execute(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]), free_function(2, args);
			exit(2);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) && status != 0)
			exit(WEXITSTATUS(status));
	}
	return (1);
}
