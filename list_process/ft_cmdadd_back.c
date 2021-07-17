#include "list.h"

void	ft_cmdadd_back(t_cmd **lst, t_cmd *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
	{
		lst = &((*lst)->next);
	}
	(*lst)->next = new;
}
