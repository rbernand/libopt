# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcosson <vcosson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/24 06:29:29 by rbernand          #+#    #+#              #
#    Updated: 2016/03/17 19:32:02 by rbernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libopt.a
CC = cc
FLAGS = -Wall -Wextra -Werror -g -O3
LIBFT = libft/
INCLUDES = include/
DIROBJ = obj/
DIRLIB = lib/
DIRSRC = src/
DIRBIN = bin/
SRC = \
	store_opt.c \
	parse_opt.c
OBJ=$(SRC:%.c=$(DIROBJ)%.o)

all: init $(NAME) end

init:
	@git submodule init
	@git submodule update
	@mkdir -p $(DIRLIB)
	@mkdir -p $(DIROBJ)
	@make -s -C $(LIBFT)
	@cd $(DIRLIB) && ln -f ../$(LIBFT)/libft.a .
	@ln -f $(LIBFT)/includes/libft.h $(INCLUDES)

end:
	@printf "\033[2K\033[1;36m%-20s\033[0;32m[Ready]\033[0m\n" $(NAME)

$(NAME): $(OBJ)
	ar -qc $(DIRLIB)$@ $^
	ranlib $(DIRLIB)$@
	@ln -f $(DIRLIB)$(NAME) $(NAME)

$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(FLAGS) -o $@ -c $< -I$(INCLUDES) -I$(HOME)/.brew/include/

clean:
	@rm -f $(OBJ)

example: $(NAME) examples/example1.c
	gcc $(FLAGS) -o $@ examples/example1.c $l$(NAME) -I$(INCLUDES)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(DIROBJ)
	@rm -rf $(DIRLIB)
	@rm -rf $(ARCHIVE_TEXTURE_NAME)

re: fclean all

lre:
	@rm -rf $(DIRLIB)
	@make -C $(LIBFT) re
	@make -C $(LIBVECT) re
	@make re
