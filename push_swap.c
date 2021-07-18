#include "push_swap.h"
#include <stdio.h>

//void	check_leaks();

void	print_stack(t_list *stack)
{
	printf("--------------\n");
	printf("%s\t%s\t%s\n", "value", "order", "flag");
	while (stack)
	{
		printf("%d\t%d\t%d\n", stack->content, stack->order, stack->flag);
		stack = stack->next;
	}
	printf("--------------\n");
}

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
		ft_cmdadd_back(cmd, ft_newcmd(6));
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

static	void	push_swap(t_list **stack_a, t_list **stack_b, t_state *state, t_cmd **cmd)
{
	if (is_sorted(*stack_a))
		return ;
	state->max = ft_lstsize(*stack_a);
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
	if (argc == 1 || !stack_a->next)
		ft_putstr("\n");
	set_order_index(stack_a);
	init_state(&state);
	if (stack_a->order == state.next)
		push_swap_first_next(&stack_a, &stack_b, &state, &cmd);
	else
		push_swap(&stack_a, &stack_b, &state, &cmd);
	print_stack(stack_a);
	print_stack(stack_b);
//	printf("%d\t%d\n", state.max, state.next);
	reduction(&cmd);
	print_commands(cmd);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	ft_cmdclear(&cmd);
//	check_leaks();
	return (0);
}
