#include "list.h"

void	ft_cmdclear(t_cmd **lst)
{
	t_cmd	*help;

	if (!*lst)
		return ;
	while (*lst)
	{
		help = *lst;
		*lst = help->next;
		free(help);
	}
}
