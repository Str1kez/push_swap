#include "push_swap.h"
#include <stdio.h>

void check_leaks();

void	print_stack(t_list *stack)
{
	printf("--------\n");
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
	printf("--------\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
//	int tc = 4;
//	char	*tv[] = {"23", "221", "434", NULL};

	stack_a = NULL;
	stack_b = NULL;
//	input_handler(&stack_a, tc, tv);
	input_handler(&stack_a, argc, argv);
	print_stack(stack_a);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	check_leaks();
	return (0);
}
