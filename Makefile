##
## EPITECH PROJECT, 2021
## BSQ
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/bsq.c	\
		src/it_is_line_or_column.c	\
		src/open_map.c	\
		lib/my/my_strlen.c	\
		lib/my/my_str_to_array.c	\

OBJ	=	$(SRC:.c=.o)
RM	=	rm -f
CFLAGS	+=	-I./include/ -L./
ERROR	=	 -Wall -Wextra
DEBUG	=	-g3

NAME	=	bsq \

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(ERROR) $(SRC)

.PHONY:	clean fclean re

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:	fclean all