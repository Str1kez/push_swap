/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:48:48 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:48:49 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorted.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->order > stack->next->order)
			return (0);
		stack = stack->next;
	}
	return (1);
}
