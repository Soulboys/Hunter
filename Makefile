##
## EPITECH PROJECT, 2018
## Delivery
## File description:
## __DESCRIPTION__
##

SRC	=	main.c  \
        sprite_use.c    \
        window.c

OBJ	=	$(SRC:.c=.o)

NAME =	my_hunter

all:	$(NAME)

LDFLAGS += -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

$(NAME):	$(OBJ)
		ar rc libmy.a $(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)
		@echo "\n_________---ce genre de \e[1;31m./$(NAME)\e[37m toi même tu sais---________\n"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libmy.a
	rm -f my.h

re: fclean	all
