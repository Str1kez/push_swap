/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:48:02 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:48:03 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_cmdclear(t_cmd **lst)
{
	t_cmd	*help;

	if (!*lst)
		return ;
	while (*lst)
	{
		help = *lst;
		*lst = help->next;
		free(help);
	}
}
