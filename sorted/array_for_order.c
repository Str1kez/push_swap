/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_for_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:48:46 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:48:47 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorted.h"

int	*array_for_order(t_list *stack)
{
	int	*arr;
	int	iter;

	iter = 0;
	arr = malloc(sizeof(int) * ft_lstsize(stack));
	while (stack)
	{
		arr[iter++] = stack->content;
		stack = stack->next;
	}
	sort_array(arr, 0, iter - 1);
	return (arr);
}
