#include "list.h"

t_cmd	*ft_newcmd(int cmd)
{
	t_cmd	*node;

	node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->cmd = cmd;
	node->next = NULL;
	return (node);
}
