/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_swap_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:50:57 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:51:01 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	add_to_cmd_false(int order, int mid, t_cmd **cmd)
{
	if (order >= mid)
		ft_cmdadd_back(cmd, ft_newcmd(3));
	else
		ft_cmdadd_back(cmd, ft_newcmd(6));
}

static	void	add_to_cmd_true(t_cmd **cmd)
{
	ft_cmdadd_back(cmd, ft_newcmd(3));
	ft_cmdadd_back(cmd, ft_newcmd(5));
}

void	first_more_then_mid(t_list **stack_b, t_list **stack_a,
							t_state *state, t_cmd **cmd)
{
	int	size_b;

	size_b = ft_lstsize(*stack_b);
	while (size_b > 0)
	{
		if ((*stack_b)->order == state->next)
		{
			push_top(stack_a, stack_b);
			rotate(stack_a);
			state->next += 1;
			add_to_cmd_true(cmd);
		}
		else
		{
			add_to_cmd_false((*stack_b)->order, state->mid, cmd);
			if ((*stack_b)->order >= state->mid)
			{
				(*stack_b)->flag = state->flag;
				push_top(stack_a, stack_b);
			}
			else
				rotate(stack_b);
		}
		size_b--;
	}
}
