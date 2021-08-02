/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:47:42 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:47:43 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		flag;

	flag = 0;
	help = arr;
	while (*arr)
	{
		content = ft_atoi(*arr, &flag);
		if (flag)
		{
			ft_lstclear(stack);
			if (is_malloc)
				clean_array(help);
		}
		check_exception(flag);
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
	check_duplicate(stack);
}
