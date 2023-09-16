/**
 * child_process_and_wait - same thing
 * @argv: input
 */
void child_process_and_wait(char **argv)
{
	pid_t pid = fork();
	if (pid == 0)
		child_process(argv);
	else
	{
		int status;
		wait(&status);
	}
}
/**
 * child_process - same
 * @argv: input
 */
void child_process(char **argv)
{
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("./shell");
		exit(1);
	}
}
