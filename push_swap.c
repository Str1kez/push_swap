#include "push_swap.h"
#include <stdio.h>

void	check_leaks();

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

static	void	init_state(t_state *state)
{
	state->flag = 0;
	state->next = 1;
	state->mid = 0;
	state->max = 0;
}

static	void	push_swap_half(t_list **stack_a,
								 t_list **stack_b, t_state *state)
{
	if (is_sorted(*stack_a))
		return ;
	state->max = ft_lstsize(*stack_a);
	state->mid = (state->max - state->next) / 2 + state->next;
	if (((*stack_a)->order == state->max) && ((*stack_a)->next->order == 1))
	{
		rotate(stack_a);
		return ;
	}
	less_then_mid_with_sorted(stack_a, stack_b, state);
	rotate_sorted_stack(stack_a, stack_b, state);
	migrate_to_a(stack_a, stack_b, state);
	while ((*stack_a)->flag)
	{
		equals_flag_to_b(stack_a, stack_b);
		migrate_to_a(stack_a, stack_b, state);
	}
	push_swap_half(stack_a, stack_b, state);
}

static	void	push_swap(t_list **stack_a, t_list **stack_b, t_state *state)
{
	if (is_sorted(*stack_a))
		return ;
	state->max = ft_lstsize(*stack_a);
	state->mid = state->max / 2 + state->next;
	first_less_then_mid(stack_a, stack_b, state);
	migrate_to_a(stack_a, stack_b, state);
	while ((*stack_a)->flag)
	{
		equals_flag_to_b(stack_a, stack_b);
		migrate_to_a(stack_a, stack_b, state);
	}
	push_swap_half(stack_a, stack_b, state);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_state	state;
//	int tc = 2;
//	char	*tv[] = {"23", "-1 -21 3 0", "434", "4", NULL};
//	char	*tv[] = {"22", "31 90 6 13 55 83 35 46 11 47 4 41 74 42 21 8 73 22 80 1 76 63 87 72 61 27 7 48 82 24 50 52 95 19 38 9 68 71 100 10 94 64 29 23 85 67 17 20 26 5 97 98 2 58 3 88 62 12 79 66 40 30 69 14 34 91 60 65 15 86 28 56 93 92 37 39 32 75 18 54 84 33 99 25 81 59 77 16 36 57 70 43 96 78 49 51 89 45 44 53"};
	stack_a = NULL;
	stack_b = NULL;

//	input_handler(&stack_a, tc, tv);
	input_handler(&stack_a, argc, argv);
	set_order_index(stack_a);
	init_state(&state);
	push_swap(&stack_a, &stack_b, &state);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("%d\t%d\n", state.max, state.next);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	check_leaks();
	return (0);
}
