/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_elem_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:39:44 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/04 20:39:47 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	next_elem_top(t_list **stack, t_state *state, t_cmd **cmd)
{
	rotate(stack);
	ft_cmdadd_back(cmd, ft_newcmd(5));
	state->next++;
}
