//
// Created by Thao Nessround on 7/3/21.
//

#ifndef SRC_H
# define SRC_H

# include "../push_swap.h"

void	ft_putstr(char *s);
void	print_command(int cmd);
void	swap_top(t_list *stack);
void	push_top(t_list **put, t_list **take);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	reduction(t_cmd **cmd);

#endif //PUSH_SWAP_SRC_H
