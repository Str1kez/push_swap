FILES		=	list_process/ft_cmdadd_back.c	\
				list_process/ft_cmdclear.c	\
				list_process/ft_cmddelete_next.c	\
				list_process/ft_lstadd_back.c	\
				list_process/ft_lstadd_front.c	\
				list_process/ft_lstclear.c	\
				list_process/ft_lstlast.c	\
				list_process/ft_lstnew.c	\
				list_process/ft_lstsize.c	\
				list_process/ft_lstswap.c	\
				list_process/ft_newcmd.c	\
				input_handlers/check_duplicate.c	\
				input_handlers/check_exception.c	\
				input_handlers/check_invalid_input.c	\
				input_handlers/ft_atoi.c	\
				input_handlers/ft_isdigit.c	\
				input_handlers/ft_split.c	\
				input_handlers/input_handler.c	\
				sorted/array_for_order.c	\
				sorted/is_sorted.c	\
				sorted/low_stack.c	\
				sorted/set_order_index.c	\
				sorted/sort_array.c	\
				sorted/three_in_stack.c	\
				src/cmd_reduction.c \
				src/ft_puststr.c \
				src/print_command.c \
				src/push_top.c \
				src/reverse_rotate.c \
				src/rotate.c \
				equals_flag_to_b.c \
				first_swap_to_a.c \
				first_swap_to_b.c \
				migrate_to_a.c \
				push_swap.c \
				push_swap_first_next.c \
				rotate_sorted_stack.c

GCC 		=	gcc
OBJS		=	$(FILES:.c=.o)
FLAGS		=	-Wall -Wextra -Werror
NAME		=	push_swap

.c.o: 
	${GCC} ${FLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	${GCC} ${FLAGS} $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, re, clean, $(NAME), fclean
