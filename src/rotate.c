#include "src.h"

void	rotate(t_list **stack)
{
	t_list	*help;

	if (!*stack || !(*stack)->next)
		return ;
	help = *stack;
	while (help->next)
		help = help->next;
	help->next = *stack;
	*stack = (*stack)->next;
	help->next->next = NULL;
}
