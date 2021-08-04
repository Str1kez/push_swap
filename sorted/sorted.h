/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:49:01 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:49:02 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTED_H
# define SORTED_H

# include "../push_swap.h"

void	sort_array(int *arr, int begin, int end);
int		*array_for_order(t_list *stack);
void	set_order_index(t_list *stack);
int		is_sorted(t_list *stack);
void	low_stack(t_list **stack_a, t_list **stack_b, t_cmd **cmd);
void	three_in_stack(t_list **stack, t_cmd **cmd, int max_order, int is_b);

#endif //FT_PRINTF_SORTED_H
