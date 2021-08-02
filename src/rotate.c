/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:50:06 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:50:07 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	rotate(t_list **stack)
{
	t_list	*help;

	if (!*stack || !(*stack)->next)
		return ;
	help = *stack;
	while (help->next)
		help = help->next;
	help->next = *stack;
	*stack = (*stack)->next;
	help->next->next = NULL;
}
