#ifndef SORTED_H
# define SORTED_H

# include "../push_swap.h"

void	sort_array(int *arr, int begin, int end);
int		*array_for_order(t_list *stack);
void	set_order_index(t_list *stack);
int		is_sorted(t_list *stack);

#endif //FT_PRINTF_SORTED_H