static	int	is_right_char(int c)
{
	if ((c < 58) && (c > 47) || c == '-')
		return (1);
	return (0);
}

static	int	check_failure(char *arg)
{
	while (*arg)
		if (!is_right_char(*arg++))
			return (1);
	return (0);
}

static	void	clean_array(char **arr)
{
	char	**help;

	help = arr;
	while (*arr)
		free(*arr++);
	free(help);
}

int	input_handler(char	**argv)
{
	while (*argv)
	{

		argv++;
	}
}
