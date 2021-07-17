#include "list.h"

void	ft_cmddel_next(t_cmd *lst)
{
	t_cmd	*help;

	if (!lst || !(lst->next))
		return ;
	help = lst->next;
	lst->next = help->next;
	free(help);
}
