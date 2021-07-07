#include "push_swap.h"

void	equals_flag_to_b(t_list **stack_a, t_list **stack_b)
{
	int	flag;

	flag = (*stack_a)->flag;
	while (flag && ((*stack_a)->flag == flag))
	{
		push_top(stack_b, stack_a);
	}
}
