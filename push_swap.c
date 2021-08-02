/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:51:07 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:51:08 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_commands(t_cmd *cmd)
{
	while (cmd)
	{
		print_command(cmd->cmd);
		cmd = cmd->next;
	}
}

static	void	init_state(t_state *state)
{
	state->flag = 0;
	state->next = 1;
	state->mid = 0;
	state->max = 0;
}

void	push_swap_half(t_list **stack_a, t_list **stack_b,
								 t_state *state, t_cmd **cmd)
{
	if (is_sorted(*stack_a))
		return ;
	state->max = ft_lstsize(*stack_a);
	state->mid = (state->max - state->next) / 2 + state->next;
	if (((*stack_a)->order == state->max) && ((*stack_a)->next->order == 1))
	{
		rotate(stack_a);
		ft_cmdadd_back(cmd, ft_newcmd(5));
		return ;
	}
	less_then_mid_with_sorted(stack_a, stack_b, state, cmd);
	rotate_sorted_stack(stack_a, stack_b, state, cmd);
	migrate_to_a(stack_a, stack_b, state, cmd);
	while ((*stack_a)->flag)
	{
		equals_flag_to_b(stack_a, stack_b, state, cmd);
		migrate_to_a(stack_a, stack_b, state, cmd);
	}
	push_swap_half(stack_a, stack_b, state, cmd);
}

static	void	push_swap(t_list **stack_a, t_list **stack_b,
							t_state *state, t_cmd **cmd)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (size_a < 6)
	{
		low_stack(stack_a, stack_b, cmd);
		return ;
	}
	state->max = size_a;
	state->mid = state->max / 2 + state->next;
	first_less_then_mid(stack_a, stack_b, state, cmd);
	migrate_to_a(stack_a, stack_b, state, cmd);
	while ((*stack_a)->flag)
	{
		equals_flag_to_b(stack_a, stack_b, state, cmd);
		migrate_to_a(stack_a, stack_b, state, cmd);
	}
	push_swap_half(stack_a, stack_b, state, cmd);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_state	state;
	t_cmd	*cmd;

	stack_a = NULL;
	stack_b = NULL;
	cmd = NULL;
	input_handler(&stack_a, argc, argv);
	if (argc == 1 || argv[1][0] == '\0')
	{
		ft_putstr("\n");
		exit(0);
	}
	set_order_index(stack_a);
	init_state(&state);
	if (stack_a->order == state.next && ft_lstsize(stack_a) > 5)
		push_swap_first_next(&stack_a, &stack_b, &state, &cmd);
	else
		push_swap(&stack_a, &stack_b, &state, &cmd);
	reduction(&cmd);
	print_commands(cmd);
	ft_lstclear(&stack_a);
	ft_cmdclear(&cmd);
	return (0);
}
