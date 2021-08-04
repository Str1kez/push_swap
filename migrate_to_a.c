/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   migrate_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:51:04 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:51:05 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	spin_a(t_list **stack_a, t_list **stack_b,
						 t_cmd **cmd, int count)
{
	while (count--)
	{
		push_top(stack_a, stack_b);
		rotate(stack_a);
		ft_cmdadd_back(cmd, ft_newcmd(3));
		ft_cmdadd_back(cmd, ft_newcmd(5));
	}
}

static	void	sort_in_b_two(t_list **stack_a, t_list **stack_b,
					t_state *state, t_cmd **cmd)
{
	if (!is_sorted(*stack_b))
	{
		ft_lstswap(*stack_b);
		ft_cmdadd_back(cmd, ft_newcmd(1));
	}
	spin_a(stack_a, stack_b, cmd, 2);
	state->next += 2;
}

static	void	sort_in_b_three(t_list **stack_a, t_list **stack_b,
					t_state *state, t_cmd **cmd)
{
	if (!is_sorted(*stack_b))
		three_in_stack(stack_b, cmd, state->next + 2, 1);
	spin_a(stack_a, stack_b, cmd, 3);
	state->next += 3;
}

void	migrate_to_a(t_list	**stack_a, t_list **stack_b,
					t_state *state, t_cmd **cmd)
{
	if (ft_lstsize(*stack_b) == 3)
	{
		sort_in_b_three(stack_a, stack_b, state, cmd);
		return ;
	}
	if (ft_lstsize(*stack_b) == 2)
	{
		sort_in_b_two(stack_a, stack_b, state, cmd);
		return ;
	}
	while (*stack_b)
	{
		state->max = state->mid;
		state->mid = (state->max - state->next) / 2 + state->next;
		state->flag++;
		first_more_then_mid(stack_b, stack_a, state, cmd);
	}
}
