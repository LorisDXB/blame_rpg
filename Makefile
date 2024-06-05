##
## EPITECH PROJECT, 2023
## myrpg
## File description:
## Makefile
##

LIB	= 	$(wildcard lib/*.c)

SRC =	$(wildcard src/*.c)	\
		$(wildcard src/dongeon/*.c)	\
		$(wildcard src/draw/*.c)	\
		$(wildcard src/enemy/*.c)	\
		$(wildcard src/fighting/*.c)	\
		$(wildcard src/init/*.c)	\
		$(wildcard src/cooldown/*.c)	\
		$(wildcard src/menu/*.c)	\
		$(wildcard src/menu/main-menu/*.c)	\
		$(wildcard src/menu/main-menu/text/*.c)	\
		$(wildcard src/menu/main-menu/rect/*.c)	\
		$(wildcard src/menu/main-menu/mouse/*.c)	\
		$(wildcard src/menu/menu-ig/*.c)	\
		$(wildcard src/menu/menu-ig/mouse/*.c)	\
		$(wildcard src/menu/menu-ig/rect/*.c)	\
		$(wildcard src/menu/menu-ig/sprite/*.c)	\
		$(wildcard src/hitboxes/*.c)	\
		$(wildcard src/inventory/*.c)	\
		$(wildcard src/save/*.c)	\
		$(wildcard src/png/*.c)	\
		$(wildcard src/text/*.c)	\
		$(wildcard src/sound/*.c)	\
		$(wildcard src/movement/*.c)	\

CFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

CPPFLAGS	:=	-Iinclude

NAME	=	libmy.a

NAME2	=	my_rpg

OBJ	=	$(LIB:.c=.o)

OBJ_SRC	=	$(SRC:.c=.o)

all:	$(NAME2) clean

$(NAME2):	$(OBJ) $(OBJ_SRC)
		ar rc $(NAME) lib/*.o
		gcc -o $(NAME2) $(OBJ_SRC) -L./ -lmy $(CFLAGS)

debug:	CFLAGS += -g3
debug:	all

clean:
		rm -f ${OBJ}
		rm -f ${OBJ_SRC}
		rm -f libmy.a
		rm -f *~
		rm -f *.log
		rm -f vgcore*

fclean: clean
		rm -f $(NAME2)
		rm -f ${OBJ}
		rm -f ${OBJ_SRC}
		rm -f libmy.a

re: fclean all

.PHONY: all clean fclean re
