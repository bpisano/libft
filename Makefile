# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpisano <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 19:19:47 by bpisano           #+#    #+#              #
#    Updated: 2017/11/15 13:23:26 by bpisano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PART1 = ft_memset.c				\
	  	ft_bzero.c				\
	  	ft_memcpy.c				\
		ft_memccpy.c			\
	  	ft_memmove.c			\
	  	ft_memchr.c				\
	  	ft_memcmp.c				\
	  	ft_strlen.c				\
	  	ft_strdup.c				\
	  	ft_strcpy.c				\
		ft_strncpy.c			\
	  	ft_strcat.c				\
	  	ft_strncat.c			\
		ft_strlcat.c			\
	  	ft_strchr.c				\
	  	ft_strrchr.c			\
	  	ft_strstr.c				\
	  	ft_strnstr.c			\
	  	ft_strcmp.c				\
	  	ft_strncmp.c			\
	  	ft_atoi.c				\
	  	ft_isalpha.c			\
	  	ft_isdigit.c			\
	  	ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_toupper.c			\
		ft_tolower.c			\

PART2 = ft_memalloc.c			\
		ft_memdel.c				\
		ft_strnew.c				\
		ft_strdel.c				\
		ft_strclr.c				\
		ft_striter.c			\
		ft_striteri.c			\
		ft_strmap.c				\
		ft_strmapi.c			\
		ft_strequ.c				\
		ft_strnequ.c			\
		ft_strsub.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_strsplit.c			\
		ft_itoa.c				\
		ft_putchar.c			\
		ft_putstr.c				\
		ft_putendl.c			\
		ft_putnbr.c				\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\

BONUS = ft_lstnew.c				\
		ft_lstdelone.c			\
		ft_lstdel.c				\
		ft_lstadd.c				\
		ft_lstiter.c			\
		ft_lstmap.c

EXTRA = ft_isblank.c			\
		ft_iscntrl.c			\
		ft_isgraph.c			\
		ft_islower.c			\
		ft_isspace.c			\
		ft_isupper.c			\
		ft_isxdigit.c			\
		ft_str_is_alpha.c		\
		ft_str_is_lowercase.c	\
		ft_str_is_numeric.c		\
		ft_str_is_printable.c	\
		ft_str_is_uppercase.c	\
		ft_strcapitalize.c		\
		ft_strlowcase.c			\
		ft_strcasestr.c			\
		ft_strlcpy.c			\
		ft_strcasecmp.c			\
		ft_strncasecmp.c		\
		ft_strndup.c			\
		ft_strupcase.c			\
		ft_itoa_base.c			\

OBJECTS = $(PART1:.c=.o) $(PART2:.c=.o) $(BONUS:.c=.o) $(EXTRA:.c=.o)

HEADS = ./

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
END = \033[0m

all: $(NAME)

$(NAME):
	@echo "\n\t$(BLUE)$(NAME)$(END)"
	@gcc $(FLAGS) -I $(HEADS) -c $(PART1) $(PART2) $(BONUS) $(EXTRA)
	@echo "\tCompiling sources\t\t$(GREEN)Done$(END)"
	@ar rc $(NAME) $(OBJECTS)
	@echo "\tCreating libft.a\t\t$(GREEN)Done$(END)"

clean:
	@echo "\n\t$(BLUE)CLEAN$(END)"
	@rm -f $(OBJECTS)
	@echo "\tRemoving objects\t\t$(GREEN)Done$(END)"

fclean: clean
	@echo "\n\t$(BLUE)FCLEAN$(END)"
	@rm -f $(NAME)
	@echo "\tRemoving libft.a\t\t$(GREEN)Done$(END)"

re: fclean all
	@echo "\n\t$(GREEN)All the process is ok$(END)\n"
