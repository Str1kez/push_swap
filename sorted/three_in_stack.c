/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_in_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:49:03 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:49:04 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorted.h"

static	void	three_in_mid_two_begin(t_list **stack, t_cmd **cmd)
{
	reverse_rotate(stack);
	ft_cmdadd_back(cmd, ft_newcmd(8));
}

static	void	three_in_mid_one_begin(t_list **stack, t_cmd **cmd)
{
	ft_lstswap(*stack);
	ft_cmdadd_back(cmd, ft_newcmd(0));
	rotate(stack);
	ft_cmdadd_back(cmd, ft_newcmd(5));
}

static	void	three_in_begin_two_middle(t_list **stack, t_cmd **cmd)
{
	ft_lstswap(*stack);
	ft_cmdadd_back(cmd, ft_newcmd(0));
	three_in_mid_two_begin(stack, cmd);
}

static	void	three_in_begin_one_middle(t_list **stack, t_cmd **cmd)
{
	rotate(stack);
	ft_cmdadd_back(cmd, ft_newcmd(5));
}

void	three_in_stack(t_list **stack, t_cmd **cmd, int max_order)
{
	if ((*stack)->next->next->order == max_order)
	{
		ft_lstswap(*stack);
		ft_cmdadd_back(cmd, ft_newcmd(0));
	}
	if ((*stack)->next->order == max_order)
	{
		if ((*stack)->order == max_order - 2)
			three_in_mid_one_begin(stack, cmd);
		else
			three_in_mid_two_begin(stack, cmd);
	}
	if ((*stack)->order == max_order)
	{
		if ((*stack)->next->order == max_order - 1)
			three_in_begin_two_middle(stack, cmd);
		else
			three_in_begin_one_middle(stack, cmd);
	}
}
