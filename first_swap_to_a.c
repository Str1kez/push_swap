#include "push_swap.h"

void	first_more_then_mid(t_list **stack_b, t_list **stack_a, t_state *state)
{
	int	size_b;

	size_b = ft_lstsize(*stack_b);
	while (size_b > 0)
	{
		if ((*stack_b)->order == state->next)
		{
			push_top(stack_a, stack_b);
			rotate(stack_a);
			state->next += 1;
		}
		else
		{
			if ((*stack_b)->order >= state->mid)
			{
				(*stack_b)->flag = state->flag;
				push_top(stack_a, stack_b);
			}
			else
				rotate(stack_b);
		}
		size_b--;
	}
}
