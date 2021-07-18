#include "push_swap.h"

static	void	spin(t_list **stack, int count, t_cmd **cmd)
{
	int	r_count;
	int	reverse;

	r_count = ft_lstsize(*stack) - count;
	reverse = r_count > count;
	if (reverse)
		r_count = count;
	while (r_count--)
	{
		if (!reverse)
		{
			reverse_rotate(stack);
			ft_cmdadd_back(cmd, ft_newcmd(8));
		}
		else
		{
			rotate(stack);
			ft_cmdadd_back(cmd, ft_newcmd(5));
		}
	}
}

static int	less_then_mid(t_list **stack_a, t_list **stack_b,
							t_state *state, t_cmd **cmd)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	while ((*stack_a)->order != 1)
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
	return (size_a);
}

void	push_swap_first_next(t_list **stack_a, t_list **stack_b,
							 t_state *state, t_cmd **cmd)
{
	int	count;

	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->order == state->next)
	{
		rotate(stack_a);
		ft_cmdadd_back(cmd, ft_newcmd(5));
		state->next++;
		push_swap_first_next(stack_a, stack_b, state, cmd);
	}
	state->max = ft_lstsize(*stack_a);
	state->mid = (state->max - state->next) / 2 + state->next;
	count = less_then_mid(stack_a, stack_b, state, cmd);
	spin(stack_a, count, cmd);
	migrate_to_a(stack_a, stack_b, state, cmd);
	while ((*stack_a)->flag)
	{
		equals_flag_to_b(stack_a, stack_b, state, cmd);
		migrate_to_a(stack_a, stack_b, state, cmd);
	}
	push_swap_half(stack_a, stack_b, state, cmd);
}
