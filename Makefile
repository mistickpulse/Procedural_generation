##
## Makefile for  in /home/fabian/rendu/PSU/PSU_2015_minishell1
## 
## Made by Zouz
## Login   <fabian@epitech.net>
## 
## Started on  Tue Jun 21 20:18:39 2016 Zouz
## Last update Fri Apr 14 11:32:01 2017 fabian.le-maux@epitech.eu
##

RCREAT =	mkdir

SRC_DIR =	src/

EXT =		.c

CC =		gcc

RMDIR =		rm -d

RM =		rm -f

CFLAGS = 	-std=gnu99

CFLAGS +=	-Wall -Wextra

NAME = 		gen_cave

SRCS_NAME =	main	\

SRCS :=		$(addprefix $(SRC_DIR), $(SRCS_NAME))

SRCS :=		$(addsuffix $(EXT), $(SRCS))

OBJS = 		$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
	@make -C ./graph 


clean:
	@$(RM) $(OBJS)
	@make -C ./graph clean

fclean: 	clean
	@make -C ./graph fclean
	@$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
