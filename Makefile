LIST_FILES	= 	./list_process/ft_lstadd_back.c	\
				./list_process/ft_lstadd_front.c	\
				./list_process/ft_lstclear.c	\
				./list_process/ft_lstlast.c	\
				./list_process/ft_lstnew.c	\
				./list_process/ft_lstsize.c

INPUT_FILES	=	./input_handlers/ft_split.c \

PS_FILES	=	print_content.c

GCC 		=	gcc
LIST_OBJS	=	$(LIST_FILES:.c=.o)
PS_OBJS		=	$(PS_FILES:.c=.o)
INPUT_OBJS	=	$(INPUT_FILES:.c=.o)
FLAGS		=	-Wall -Wextra -Werror
NAME		=	push_swap

.c.o: 
	${GCC} ${FLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(LIST_OBJS) $(SRC_OBJS) $(PS_OBJS)
	${GCC} ${FLAGS} $(LIST_OBJS) $(INPUT_OBJS) $(PS_OBJS) -o $(NAME)

clean:
	rm -rf $(LIST_OBJS) $(INPUT_OBJS) $(PS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, re, clean, $(NAME), fclean
