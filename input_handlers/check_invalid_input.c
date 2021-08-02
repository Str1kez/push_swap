/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:47:27 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:47:28 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handlers.h"

int	check_invalid_input(const char *arg)
{
	if (!ft_isdigit(*arg) && !(*arg == '-' && ft_isdigit(*(arg + 1))))
		return (1);
	if (*arg == '-')
		arg++;
	while (*arg)
		if (!ft_isdigit(*arg++))
			return (1);
	return (0);
}
