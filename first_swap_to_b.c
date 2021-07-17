#include "push_swap.h"

void	first_less_then_mid(t_list **stack_a, t_list **stack_b,
							t_state *state, t_cmd **cmd)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	while (size_a > 0)
	{
		if ((*stack_a)->order <= state->mid)
		{
			push_top(stack_b, stack_a);
			ft_cmdadd_back(cmd, ft_newcmd(4));
		}
		else
		{
			rotate(stack_a);
			ft_cmdadd_back(cmd, ft_newcmd(5));
		}
		size_a--;
	}
}

void	less_then_mid_with_sorted(t_list **stack_a, t_list **stack_b,
								  t_state *state, t_cmd **cmd)
{
	while ((*stack_a)->order > 1)
	{
		if ((*stack_a)->order <= state->mid)
		{
			push_top(stack_b, stack_a);
			ft_cmdadd_back(cmd, ft_newcmd(4));
		}
		else
		{
			rotate(stack_a);
			ft_cmdadd_back(cmd, ft_newcmd(5));
		}
	}
}
