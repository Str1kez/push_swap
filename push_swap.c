#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
	input_handler(&stack_a, argc, argv);
	printf("%d\n", stack_a->content);
	printf("%d\n", stack_a->next->content);
	ft_lstclear(&stack_a);
	return (0);
}
