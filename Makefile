NAME =	push_swap

CC =	gcc
CFLAGS =	-g -Wall -Wextra -Werror -MMD

RM =	rm -rf

SRC =   push_swap.c		\
		utils.c			\
		check_input.c	\
		main.c			\
		push.c			\
		swap.c			\
		rotate.c		\
		reverse_rotate.c	\
		long_long_sort.c		\
		long_sort.c		\
		sort_utils.c	\

INC = 	-I push_swap.h		\
		-I libft/libft.h 	\

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

LD_FLAGS =	-L libft

.PHONY :	all clean re fclean

.c.o :		
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}


$(NAME):	$(OBJS)
			make -C ./libft/
			make bonus  -C ./libft/
			${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP)
			make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			make fclean -C libft/

re: 		fclean all

-include $(DEP)