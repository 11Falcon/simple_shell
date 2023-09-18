void single_commands(char **i_i)
{
	if (i_i[0] == NULL)
		continue;
	if (compare(i_i[0], "exit"))
	{
		free(ash);
		exit(1);
	}
	if (compare(i_i[0], "env"))
		_environ(argv);
}
