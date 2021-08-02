/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:47:46 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:47:47 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLERS_H
# define INPUT_HANDLERS_H

# include <stdlib.h>
# include "../push_swap.h"

char	**ft_split(char const *s, char c);
void	input_handler(t_list **stack, int argc, char **argv);
int		check_invalid_input(const char *arg);
int		ft_isdigit(int c);
int		ft_atoi(const char *str, int *flag);
void	check_exception(int exc);
void	check_duplicate(t_list **stack);

#endif