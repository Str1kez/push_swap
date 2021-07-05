#include "input_handlers.h"

static	void	clean_array(char **arr)
{
	char	**help;

	help = arr;
	while (*arr)
		free(*arr++);
	free(help);
}

static	void	arr_to_list(t_list **stack, char **arr, int is_malloc)
{
	int		content;
	char	**help;

	help = arr;
	while (*arr)
	{
		content = ft_atoi(*arr);
		if (content == -1)
		{
			ft_lstclear(stack);
			if (is_malloc)
				clean_array(help);
		}
		check_exception(content);
		ft_lstadd_back(stack, ft_lstnew(content));
		arr++;
	}
}

void	input_handler(t_list **stack, int argc, char **argv)
{
	char	**arr;

	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		arr_to_list(stack, arr, 1);
		clean_array(arr);
	}
	if (argc > 2)
		arr_to_list(stack, argv + 1, 0);
}
