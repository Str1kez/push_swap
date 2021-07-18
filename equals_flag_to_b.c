#include "push_swap.h"

static	int	last_order(t_list *stack_a)
{
	while (stack_a->next)
	{
		stack_a = stack_a->next;
	}
	return (stack_a->order);
}

void	equals_flag_to_b(t_list **stack_a, t_list **stack_b,
						 t_state *state, t_cmd **cmd)
{
	int	flag;

	flag = (*stack_a)->flag;
	while (flag && ((*stack_a)->flag == flag))
	{
		if ((last_order(*stack_a) == state->next - 1)
			&& ((*stack_a)->order == state->next))
		{
			rotate(stack_a);
			ft_cmdadd_back(cmd, ft_newcmd(5));
			state->next++;
		}
		else
		{
			push_top(stack_b, stack_a);
			ft_cmdadd_back(cmd, ft_newcmd(4));
		}
	}
}
