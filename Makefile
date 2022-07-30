##
## EPITECH PROJECT, 2021
## B-NWP-400-MPL-4-1-myteams-clement.ozor
## File description:
## Makefile
##

CC		=	gcc
CPPFLAGS 	= 	-I include
CFLAGS		=	-Wall -Wextra -fPIC -shared
SRC		=	$(wildcard src/*.c)
NAME		= 	libgc.so

all:	$(NAME)

$(NAME):
	@ echo "\033[1;37mGC Library Compilation...\033[0m"
	@ $(CC) -c $(SRC) $(CPPFLAGS)
	@ $(CC) -o $(NAME) *.o $(CFLAGS)
	@ echo "\033[1;34m[OK] \033[1;32mCompiled GC Library\033[0m\033[1;31m [$(NAME)]\033[0m"

clean:
	@ $(RM) *.o
	@ echo "\033[1;34m[OK] \033[1;32mGC Library Object Cleaned\033[0m"

fclean: clean
	@ $(RM) $(NAME)
	@ echo "\033[1;34m[OK] \033[1;32mGC Library Cleaned\033[\033[0m\033[1;31m [$(NAME)]\033[0m"

re:	fclean all
