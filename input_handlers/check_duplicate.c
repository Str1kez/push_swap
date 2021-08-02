/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:47:03 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:47:05 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handlers.h"

void	check_duplicate(t_list **stack)
{
	t_list	*help;
	t_list	*head;

	head = *stack;
	while (head)
	{
		help = head->next;
		while (help)
		{
			if (head->content == help->content)
			{
				ft_lstclear(stack);
				check_exception(1);
			}
			help = help->next;
		}
		head = head->next;
	}
}
