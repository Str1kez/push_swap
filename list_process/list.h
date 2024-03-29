/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:48:35 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:48:37 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				order;
	int				flag;
	struct s_list	*next;
}		t_list;

typedef struct s_cmd
{
	int				cmd;
	struct s_cmd	*next;
}		t_cmd;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstswap(t_list *stack);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_cmd	*ft_newcmd(int cmd);
void	ft_cmdclear(t_cmd **lst);
void	ft_cmdadd_back(t_cmd **lst, t_cmd *new);
void	ft_cmddel_next(t_cmd *lst);

#endif
