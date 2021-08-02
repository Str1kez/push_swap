/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:48:29 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:48:32 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstswap(t_list *stack)
{
	int	content;
	int	order;
	int	flag;

	if (!stack || !stack->next)
		return ;
	content = stack->content;
	order = stack->order;
	flag = stack->flag;
	stack->content = stack->next->content;
	stack->order = stack->next->order;
	stack->flag = stack->next->flag;
	stack->next->content = content;
	stack->next->order = order;
	stack->next->flag = flag;
}
