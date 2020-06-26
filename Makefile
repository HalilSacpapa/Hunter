##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

CC 	=	gcc

RM	=	rm -f

CSFML	=	-l c_graph_prog

NAME	=	my_hunter

SRC 	= 	src/my_hunter.c	\
		src/init.c	\
		src/clock_annim.c	\
		src/basic_fun.c	\
		src/help.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -g -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(CSFML)
	rm -f $(OBJ)

.SILENT: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(CSFML)

clean:	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
