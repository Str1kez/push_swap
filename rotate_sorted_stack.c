/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sorted_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:51:09 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:51:15 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	best_path(t_list *stack, int *reverse)
{
	int	sorted_size;
	int	stack_size;

	stack_size = ft_lstsize(stack);
	sorted_size = 0;
	while (stack->next && (stack->next->order - 1 == stack->order))
	{
		stack = stack->next;
		sorted_size++;
	}
	if (stack->next && sorted_size > 0)
		sorted_size++;
	*reverse = sorted_size > (stack_size - sorted_size);
	if (*reverse)
		return (stack_size - sorted_size);
	return (sorted_size);
}

static	int	next_on_top(t_list *stack_b, int *reverse, int next)
{
	int	size_b;
	int	index;

	index = 0;
	size_b = ft_lstsize(stack_b);
	while (stack_b->order != next)
	{
		index++;
		stack_b = stack_b->next;
	}
	*reverse = index > (size_b - index);
	if (*reverse)
		return (size_b - index);
	return (index);
}

static	void	spin(t_list **stack, int reverse, t_cmd **cmd, int flag)
{
	if (reverse)
	{
		reverse_rotate(stack);
		ft_cmdadd_back(cmd, ft_newcmd(8 + flag));
	}
	else
	{
		rotate(stack);
		ft_cmdadd_back(cmd, ft_newcmd(5 + flag));
	}
}

void	rotate_sorted_stack(t_list **stack_a, t_list **stack_b,
							t_state *state, t_cmd **cmd)
{
	int	reverse_a;
	int	reverse_b;
	int	ra_count;
	int	rb_count;

	ra_count = best_path(*stack_a, &reverse_a);
	rb_count = next_on_top(*stack_b, &reverse_b, state->next);
	while (ra_count > 0)
	{
		spin(stack_a, reverse_a, cmd, 0);
		if (rb_count > 0)
		{
			spin(stack_b, reverse_b, cmd, 1);
			rb_count--;
		}
		ra_count--;
	}
	while (rb_count-- > 0)
		spin(stack_b, reverse_b, cmd, 1);
}
