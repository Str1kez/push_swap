#include "sorted.h"

static	void	min_to_stack_b(t_list **stack_a, t_list **stack_b,
								t_cmd **cmd, int min_order)
{
	if ((*stack_a)->order != min_order)
	{
		if ((*stack_a)->next->next->next->order == min_order)
		{
			if (ft_lstsize(*stack_a) == 5)
			{
				reverse_rotate(stack_a);
				ft_cmdadd_back(cmd, ft_newcmd(8));
			}
			reverse_rotate(stack_a);
			ft_cmdadd_back(cmd, ft_newcmd(8));
		}
		else
		{
			if ((*stack_a)->next->next->order == min_order)
			{
				rotate(stack_a);
				ft_cmdadd_back(cmd, ft_newcmd(5));
			}
			rotate(stack_a);
			ft_cmdadd_back(cmd, ft_newcmd(5));
		}
	}
	push_top(stack_b, stack_a);
	ft_cmdadd_back(cmd, ft_newcmd(4));
}

static	void	two_in_stack(t_list **stack, t_cmd **cmd)
{
	ft_lstswap(*stack);
	ft_cmdadd_back(cmd, ft_newcmd(0));
}

static	void	four_in_stack(t_list **stack_a, t_list **stack_b, t_cmd **cmd)
{
	min_to_stack_b(stack_a, stack_b, cmd, 1);
	three_in_stack(stack_a, cmd, 4);
	push_top(stack_a, stack_b);
	ft_cmdadd_back(cmd, ft_newcmd(3));
}

static	void	five_in_stack(t_list **stack_a, t_list **stack_b, t_cmd **cmd)
{
	if ((*stack_a)->next->next->next->next->order == 1)
	{
		reverse_rotate(stack_a);
		ft_cmdadd_back(cmd, ft_newcmd(8));
	}
	min_to_stack_b(stack_a, stack_b, cmd, 1);
	min_to_stack_b(stack_a, stack_b, cmd, 2);
	three_in_stack(stack_a, cmd, 5);
	push_top(stack_a, stack_b);
	ft_cmdadd_back(cmd, ft_newcmd(3));
	push_top(stack_a, stack_b);
	ft_cmdadd_back(cmd, ft_newcmd(3));
}

void	low_stack(t_list **stack_a, t_list **stack_b, t_cmd **cmd)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	if (size_a == 2)
		two_in_stack(stack_a, cmd);
	if (size_a == 3)
		three_in_stack(stack_a, cmd, 3);
	if (size_a == 4)
		four_in_stack(stack_a, stack_b, cmd);
	if (size_a == 5)
		five_in_stack(stack_a, stack_b, cmd);
}
