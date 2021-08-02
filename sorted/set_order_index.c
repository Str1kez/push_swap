/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_order_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:48:56 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:48:57 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorted.h"

static	int	get_index(int content, int *arr, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		if (arr[i] == content)
			return (i);
		i++;
	}
	return (-1);
}

void	set_order_index(t_list *stack)
{
	int	*arr;
	int	size;

	size = ft_lstsize(stack);
	arr = array_for_order(stack);
	while (stack)
	{
		stack->order = get_index(stack->content, arr, size) + 1;
		stack = stack->next;
	}
	free(arr);
}
