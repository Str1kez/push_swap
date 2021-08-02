/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:49:58 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:49:59 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	print_command(int cmd)
{
	if (cmd == 0)
		ft_putstr("sa");
	if (cmd == 1)
		ft_putstr("sb");
	if (cmd == 2)
		ft_putstr("ss");
	if (cmd == 3)
		ft_putstr("pa");
	if (cmd == 4)
		ft_putstr("pb");
	if (cmd == 5)
		ft_putstr("ra");
	if (cmd == 6)
		ft_putstr("rb");
	if (cmd == 7)
		ft_putstr("rr");
	if (cmd == 8)
		ft_putstr("rra");
	if (cmd == 9)
		ft_putstr("rrb");
	if (cmd == 10)
		ft_putstr("rrr");
	ft_putstr("\n");
}
