#include "list.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*help;

	if (!*lst)
		return ;
	while (*lst)
	{
		help = *lst;
		*lst = help->next;
		del(help->content);
		free(help);
	}
}
