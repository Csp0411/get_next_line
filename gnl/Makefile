NAME = libft.a

SRCS = get_next_line_utils.c get_next_line.c 

OBJS = ${SRCS:.c=.o}

CC		= cc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}
		ranlib ${NAME}

bonus:	${all} 
		ar rcs ${NAME} 
		ranlib ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

comp: 
	cc -Wall -Werror -Wextra -L. -lft man.c && ./a.out

.PHONY: all clean fclean re
