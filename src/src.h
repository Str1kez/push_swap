/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:50:08 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:50:12 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "../push_swap.h"

void	ft_putstr(char *s);
void	print_command(int cmd);
void	push_top(t_list **put, t_list **take);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	reduction(t_cmd **cmd);

#endif //PUSH_SWAP_SRC_H
