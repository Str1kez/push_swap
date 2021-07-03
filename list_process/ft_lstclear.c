#include "list.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*help;

	if (!*lst)
		return ;
	while (*lst)
	{
		help = *lst;
		*lst = help->next;
		free(help);
	}
}
