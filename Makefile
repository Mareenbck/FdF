NAME	= fdf 

LIB_DIR = ./libft

LIBFT	= ./libft/libft.a

SRCS	= main.c map.c

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBX_DIR = ./minilibx_x11
	LDLIBS = -lXext -lX11
else
	LIBX_DIR = ./minilibx_macos
	LDLIBS = -framework OpenGL -framework AppKit
endif

all:		${NAME}

.c.o:
		@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${LIBFT}
			@echo "\033[34m----Compiling----"
			@${CC} ${OBJS} -L ${LIBX_DIR} -lmlx ${LDLIBS} -o ${NAME} ${LIBFT}
			@echo "OK"

${LIBFT}:
			@echo "\033[35m----Building libft----"
			@make -sC libft
			@echo "OK"

clean:
			@echo "\033[31m----Cleaning libft----"
			@make clean -sC ${LIB_DIR}
			@echo "OK"
			@echo "\033[31m----Cleaning objects----"
			@${RM} ${OBJS}
			@echo "OK"

fclean:		clean
			@echo "\033[33m----Cleaning all----"
			@${RM} ${NAME}
			@${RM} ${LIBFT}
			@echo "OK"

memory:		${OBJS}
			${CC} ${OBJS} -fsanitize=address -g3 -lmlx -framework openGL -framework AppKit -o ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


