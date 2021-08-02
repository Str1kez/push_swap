/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:50:04 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:50:06 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*help;
	t_list	*end;

	if (!*stack || !(*stack)->next)
		return ;
	help = *stack;
	while (help->next)
	{
		if (!help->next->next)
			end = help;
		help = help->next;
	}
	help->next = *stack;
	*stack = help;
	end->next = NULL;
}
