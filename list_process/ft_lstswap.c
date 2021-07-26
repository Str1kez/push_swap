#include "list.h"

void	ft_lstswap(t_list *stack)
{
	int	content;
	int	order;
	int	flag;

	if (!stack || !stack->next)
		return ;
	content = stack->content;
	order = stack->order;
	flag = stack->flag;
	stack->content = stack->next->content;
	stack->order = stack->next->order;
	stack->flag = stack->next->flag;
	stack->next->content = content;
	stack->next->order = order;
	stack->next->flag = flag;
}
