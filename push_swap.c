#include "push_swap.h"
#include <stdio.h>

void check_leaks();

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*copy;
//	int tc = 4;
//	char	*tv[] = {"23", "221", "434", NULL};

	stack_a = NULL;
	stack_b = NULL;
//	input_handler(&stack_a, tc, tv);
	input_handler(&stack_a, argc, argv);
	check_duplicate(&stack_a);
	copy = stack_a;
	while (copy)
	{
		printf("%d\n", copy->content);
		copy = copy->next;
	}
	ft_lstclear(&stack_a);
	check_leaks();
	return (0);
}
