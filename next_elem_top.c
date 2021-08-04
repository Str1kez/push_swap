#include "push_swap.h"

void	next_elem_top(t_list **stack, t_state *state, t_cmd **cmd)
{
	rotate(stack);
	ft_cmdadd_back(cmd, ft_newcmd(5));
	state->next++;
}
