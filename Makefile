NAME =  push_swap
SRCF =  main.c \
        ft_basic_action.c \
        ft_lst_func.c \
        ft_free_exit.c \
        ft_parsing.c \
        ft_parsing2.c \
        ft_set_pos.c \
        ft_utils.c \
        ft_utils2.c \
        ft_sort3.c \
        ft_sort5.c \
        ft_sort_chunk.c
SRCS = $(addprefix srcs/, ${SRCF})
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = ${SRCS:.c=.o}

all :   ${NAME}

%.o :  %.c include/push_swap.h libft/libft.h
			${CC} ${CFLAGS} -c $< -o $@ -I include/ -I libft/

${NAME} : ${OBJ}
			make -C libft/
			${CC} -o ${NAME} ${OBJ} libft/libft.a

checker :
			make -C mychecker/
			cp mychecker/checker ./

clean :
			make clean -C libft/
			make clean -C mychecker/
			rm -f ${OBJ}

fclean :  clean
			make fclean -C libft/
			make fclean -C mychecker/
			rm -f checker
			rm -f ${NAME}

re :    fclean ${NAME}

.PHONY : re clean fclean libft .c.o checker