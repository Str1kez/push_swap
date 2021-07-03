#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}		t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
//void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
//t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
//int		ft_lstsize(t_list *lst);

#endif
