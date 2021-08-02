/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reduction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:49:53 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:49:55 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

static	int	paste_ss(t_cmd *cmd)
{
	if (!cmd->next)
		return (0);
	if ((cmd->cmd == 1 && cmd->next->cmd == 0)
		|| (cmd->cmd == 0 && cmd->next->cmd == 1))
	{
		ft_cmddel_next(cmd);
		cmd->cmd = 2;
		return (1);
	}
	return (0);
}

static	int	paste_rr(t_cmd *cmd)
{
	if (!cmd->next)
		return (0);
	if ((cmd->cmd == 5 && cmd->next->cmd == 6)
		|| (cmd->cmd == 6 && cmd->next->cmd == 5))
	{
		ft_cmddel_next(cmd);
		cmd->cmd = 7;
		return (1);
	}
	return (0);
}

static	int	paste_rrr(t_cmd *cmd)
{
	if (!cmd->next)
		return (0);
	if ((cmd->cmd == 8 && cmd->next->cmd == 9)
		|| (cmd->cmd == 9 && cmd->next->cmd == 8))
	{
		ft_cmddel_next(cmd);
		cmd->cmd = 10;
		return (1);
	}
	return (0);
}

void	reduction(t_cmd **cmd)
{
	t_cmd	*help;

	help = *cmd;
	while (help)
	{
		if (paste_rr(help) || paste_ss(help) || paste_rrr(help))
			help = *cmd;
		else
			help = help->next;
	}
}
