#include "sorted.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->order > stack->next->order)
			return (0);
		stack = stack->next;
	}
	return (1);
}
