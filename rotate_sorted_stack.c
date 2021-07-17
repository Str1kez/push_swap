#include "push_swap.h"

static	int	best_path(t_list *stack, int *reverse)
{
	int	sorted_size;
	int stack_size;

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

static	int next_on_top(t_list *stack_b, int *reverse, int next)
{
	int size_b;
	int index;

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

static	void	spin(t_list **stack, int reverse)
{
	if (reverse)
		reverse_rotate(stack);
	else
		rotate(stack);
}

void	rotate_sorted_stack(t_list **stack_a, t_list **stack_b, t_state *state)
{
	int	reverse_a;
	int reverse_b;
	int	ra_count;
	int rb_count;

	ra_count = best_path(*stack_a, &reverse_a);
	rb_count = next_on_top(*stack_b, &reverse_b, state->next);
	while (ra_count > 0)
	{
		spin(stack_a, reverse_a);
		if (rb_count > 0)
		{
			spin(stack_b, reverse_b);
			rb_count--;
		}
		ra_count--;
	}
	while (rb_count-- > 0)
		spin(stack_b, reverse_b);
}
