##
## Makefile for  in /home/samy.aitouakli/livecoding/graph
## 
## Made by Samy Aitouakli
## Login   <samy.aitouakli@epitech.net>
## 
## Started on  Tue Apr 11 10:42:29 2017 Samy Aitouakli
## Last update Fri Apr 14 10:45:05 2017 fabian.le-maux@epitech.eu
##

CC	= 	g++

NAME	= 	graphics

CPPFLAGS +=	-W -Werror -Wall -I./include

LDFLAGS	+=	-lsfml-graphics -lsfml-window -lsfml-system

SRCS	=	srcs/live_sfml.cpp \
		srcs/live_map.cpp \
		srcs/main.cpp

OBJS	= 	$(SRCS:.cpp=.o)

all:		$(NAME)
		cp $(NAME) ../

$(NAME): 	$(OBJS)
	 	$(CC) $(CPPFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)
		rm -f ../$(NAME)

re:		fclean all

.PHONY:		all clean fclean re

