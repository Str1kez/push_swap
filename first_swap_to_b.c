#include "push_swap.h"

void	first_less_then_mid(t_list **stack_a, t_list **stack_b, t_state *state)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	while (size_a > 0)
	{
		if ((*stack_a)->order <= state->mid)
			push_top(stack_b, stack_a);
		else
			rotate(stack_a);
		size_a--;
	}
}
