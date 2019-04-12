##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile rush
##

DIR_SRC	=	./src/
DIR_INC	=	./include/

NAME	=	cesar

SRC	=	$(DIR_SRC)main.c \
		$(DIR_SRC)read_file.c \
		$(DIR_SRC)error_gestion.c \
		$(DIR_SRC)encrypt.c

OBJS	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -I$(DIR_INC)
LDFLAGS	+=	-L$(DIR_LIB) -lmy

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		gcc -o $(NAME) $(OBJS) $(LDFLAGS)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
