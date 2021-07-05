#include "src.h"

void	push_top(t_list **put, t_list **take)
{
	t_list	*help;

	if (!*take)
		return ;
	help = (*take)->next;
	(*take)->next = *put;
	*put = *take;
	*take = help;
}
