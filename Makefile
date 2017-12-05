# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpisano <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 19:19:47 by bpisano           #+#    #+#              #
#    Updated: 2017/11/24 15:46:50 by htaillef    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = gnl

SRC = ./get_next_line.c			\
	  ./main.c					\

OBJECTS = $(SRC:.c=.o)

LIB = libft.a

HEADS = ./includes

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
END = \033[0m

all: $(NAME)

$(LIB):
	@(cd libft/ && make)

$(NAME): $(LIB) $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) libft/$(LIB)

%.o : %.c
	@gcc $(FLAGS) -I $(HEADS) -o $@ -c $<

il:
	@git clone https://github.com/bpisano/libft.git libft

ul:
	@rm -Rf libft
	@git clone https://github.com/bpisano/libft.git libft

clean:
	@rm -rf $(OBJECTS)
	@(cd libft/ && make clean)

fclean: clean
	@rm -rf $(NAME)
	@(cd libft/ && make fclean)

re: fclean ul all
	@echo "\n\t$(GREEN)All the process is ok$(END)\n"
	@(cd libft/ && make re)
