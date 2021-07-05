#include "src.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*help;
	t_list	*end;

	if (!*stack || !(*stack)->next)
		return ;
	help = *stack;
	while (help->next)
	{
		if (!help->next->next)
			end = help;
		help = help->next;
	}
	help->next = *stack;
	*stack = help;
	end->next = NULL;
}
