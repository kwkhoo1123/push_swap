NAME = push_swap
NAMEB = checker

SRC = end.c init_checker.c list_util.c list_util2.c \
		op_case.c op_p.c op_r.c op_s.c list_get.c algo_small.c \
		algo_big.c list_sort.c a_util.c b_util.c rot_a_cost.c \
		list_util3.c list_get2.c median_sort.c median_sort_b.c \
		op_util.c rot_b_cost.c list_get3.c

SRCM = push_swap.c
SRCB = checker.c

OBJS 	= ${SRCS:.c=.o}
OBJM 	= ${SRCM:.c=.o}
OBJB 	= ${SRCB:.c=.o}

CC = gcc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address

LIBFT = -L ./libft -lft

.c.o:		%.o : %.c
					@${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all: $(OBJS) $(OBJM)
			@echo "Compiling push_swap"
			@make re -C ./libft
			${CC} ${CFLAGS} ${SRC} ${SRCM} ${LIBFT} -o ${NAME}
			@echo "push_swap compiled!"

bonus: $(OBJS) $(OBJB)
			@echo "Compiling push_swap"
			@make re -C ./libft
			${CC} ${CFLAGS} ${SRC} ${SRCB} ${LIBFT} -o ${NAMEB}
			@echo "push_swap compiled!"

clean:
	@make clean -C ./libft
	rm -rf *.o

fclean: clean
	@make fclean -C ./libft
	rm -f ${OBJS} ${OBJM} ${OBJB} $(NAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re bonus