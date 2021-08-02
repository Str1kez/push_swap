/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:50:00 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:50:01 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	push_top(t_list **put, t_list **take)
{
	t_list	*help;

	if (!*take)
		return ;
	help = (*take)->next;
	(*take)->next = *put;
	*put = *take;
	*take = help;
}
