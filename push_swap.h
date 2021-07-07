//
// Created by Thao Nessround on 7/3/21.
//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "list_process/list.h"
# include "src/src.h"
# include "input_handlers/input_handlers.h"
# include "sorted/sorted.h"

typedef struct s_state
{
	int	next;
	int	mid;
	int	max;
	int	flag;
}		t_state;

void	first_less_then_mid(t_list **stack_a, t_list **stack_b, t_state *state);
void	first_more_then_mid(t_list **stack_b, t_list **stack_a, t_state *state);
void	migrate_to_a(t_list	**stack_a, t_list **stack_b, t_state *state);
void	equals_flag_to_b(t_list **stack_a, t_list **stack_b);

#endif //PUSH_SWAP_H
