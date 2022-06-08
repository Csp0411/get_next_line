NAME = get_next_line.a

SRCS = get_next_line.c 

SRCS_B = 

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

CC		= cc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}
		ranlib ${NAME}

bonus:	${NAME} ${OBJS_B}
		ar rcs ${NAME} ${OBJS_B}
		ranlib ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJS_B}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
