/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmddelete_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:48:04 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:48:11 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_cmddel_next(t_cmd *lst)
{
	t_cmd	*help;

	if (!lst || !(lst->next))
		return ;
	help = lst->next;
	lst->next = help->next;
	free(help);
}
