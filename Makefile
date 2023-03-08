# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 16:18:33 by mpalkov           #+#    #+#              #
#    Updated: 2023/03/08 15:05:02 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLI	=	client

NAME_SRV	=	server

#---- FILES ----

SRC_CLI		=	client.c

SRC_SRV		=	server.c

#---- DIRECTORIES ----

LIBFT_DIR	=	utils/libft/

SRC_DIR		=	src/

#---- COMMANDS ----

CC			=	cc

CFLAGS		+=	-MMD -MP -MT $@

CFLAGS		+=	-Wall -Werror -Wextra

RM			=	rm -f

CP			=	cp -f

#---- RULES ----

LIBFT		=	$(LIBFT_DIR)libft.a

INCLUDE		=	-I./utils/libft/includes/ -I./utils/libft/ -I./includes/

all: $(NAME_SRV) $(NAME_CLI)

$(NAME_SRV): $(SRC_SRV)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_SRV) -L$(LIBFT_DIR) -lft -o $@

$(NAME_CLI): $(SRC_CLI)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_CLI) -L$(LIBFT_DIR) -lft -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) -r *.d 

fclean: clean
	$(RM) $(NAME_SRV) $(NAME_CLI)

re: fclean all

.PHONY: all, clean, fclean, re
