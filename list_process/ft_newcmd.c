/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:48:33 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:48:34 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_cmd	*ft_newcmd(int cmd)
{
	t_cmd	*node;

	node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->cmd = cmd;
	node->next = NULL;
	return (node);
}
