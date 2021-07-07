#include "sorted.h"

int	*array_for_order(t_list *stack)
{
	int	*arr;
	int	iter;

	iter = 0;
	arr = malloc(sizeof(int) * ft_lstsize(stack));
	while (stack)
	{
		arr[iter++] = stack->content;
		stack = stack->next;
	}
	sort_array(arr, 0, iter - 1);
	return (arr);
}
