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

void	migrate_to_a(t_list	**stack_a, t_list **stack_b,
					t_state *state, t_cmd **cmd)
{
	while (*stack_b)
	{
		state->max = state->mid;
		state->mid = (state->max - state->next) / 2 + state->next;
		state->flag++;
		first_more_then_mid(stack_b, stack_a, state, cmd);
	}
}
