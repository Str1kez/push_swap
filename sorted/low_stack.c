#include "sorted.h"

static	void	two_in_stack(t_list **stack, t_cmd **cmd)
{
	ft_lstswap(*stack);
	ft_cmdadd_back(cmd, ft_newcmd(0));
}

static	void	three_in_stack(t_list **stack, t_cmd **cmd)
{
	// TODO: Realize this
}

void	low_stack(t_list **stack_a, t_list **stack_b, t_cmd **cmd)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	if (size_a == 2)
		two_in_stack(stack_a, cmd);
	if (size_a == 3)
		three_in_stack(stack_a, cmd);
}
