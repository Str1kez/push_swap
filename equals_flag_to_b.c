/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equals_flag_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:50:54 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:50:56 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	equals_flag_to_b(t_list **stack_a, t_list **stack_b,
						 t_state *state, t_cmd **cmd)
{
	int	flag;

	flag = (*stack_a)->flag;
	while (flag && ((*stack_a)->flag == flag))
	{
		if ((*stack_a)->order == state->next)
		{
			rotate(stack_a);
			ft_cmdadd_back(cmd, ft_newcmd(5));
			state->next++;
		}
		else
		{
			push_top(stack_b, stack_a);
			ft_cmdadd_back(cmd, ft_newcmd(4));
		}
	}
}
