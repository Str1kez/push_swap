/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:51:16 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:51:24 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Thao Nessround on 7/3/21.
//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "list_process/list.h"
# include "src/src.h"
# include "input_handlers/input_handlers.h"
# include "sorted/sorted.h"

typedef struct s_state
{
	int	next;
	int	mid;
	int	max;
	int	flag;
}		t_state;

void	first_less_then_mid(t_list **stack_a, t_list **stack_b,
			t_state *state, t_cmd **cmd);
void	first_more_then_mid(t_list **stack_b, t_list **stack_a,
			t_state *state, t_cmd **cmd);
void	migrate_to_a(t_list	**stack_a, t_list **stack_b,
			t_state *state, t_cmd **cmd);
void	equals_flag_to_b(t_list **stack_a, t_list **stack_b,
			t_state *state, t_cmd **cmd);
void	less_then_mid_with_sorted(t_list **stack_a,
			t_list **stack_b, t_state *state, t_cmd **cmd);
void	rotate_sorted_stack(t_list **stack_a, t_list **stack_b,
			t_state *state, t_cmd **cmd);
void	push_swap_half(t_list **stack_a, t_list **stack_b,
			t_state *state, t_cmd **cmd);
void	push_swap_first_next(t_list **stack_a, t_list **stack_b,
			t_state *state, t_cmd **cmd);
void	next_elem_top(t_list **stack, t_state *state, t_cmd **cmd);

#endif //PUSH_SWAP_H
