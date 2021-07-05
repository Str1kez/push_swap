#include "src.h"

void	swap_top(t_list *stack)
{
	int	swap;

	if (!stack)
		return ;
	if (stack->next)
	{
		swap = stack->content;
		stack->content = stack->next->content;
		stack->next->content = swap;
	}
}
