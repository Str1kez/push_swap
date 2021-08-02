/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:48:20 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:48:21 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*help;

	if (!*lst)
		return ;
	while (*lst)
	{
		help = *lst;
		*lst = help->next;
		free(help);
	}
}
