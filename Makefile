# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 16:18:33 by mpalkov           #+#    #+#              #
#    Updated: 2023/02/21 14:52:46 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLI	=	client

NAME_SRV	=	server

#---- FILES ----

SRC_CLI		=	client.c

SRC_SRV		=	server.c

#---- DIRECTORIES ----

LIBFT_DIR	=	utils/libft/

#OBJ_DIR		=	obj/

SRC_DIR		=	src/

#UTILS_DIR	=	utils/

#---- COMMANDS ----

CC			=	cc

CFLAGS		+=	-MMD -MP -MT $@

#CFLAGS		+=	-Wall -Werror -Wextra

RM			=	rm -f

CP			=	cp -f

#---- RULES ----

LIBFT		=	$(LIBFT_DIR)libft.a

#OBJ			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

INCLUDE		=	-I./utils/libft/includes/ -I./utils/libft/

#DEPS		=	$(addsuffix .d,$(basename $(OBJ)))

#UTILS		=	$(addprefix $(UTILS_DIR),$(UTILS_PRINTF))

#SRCS		+=	$(addprefix $(SRC_DIR),$(SRC_PRINTF))

#SRCS		+=	$(addprefix $(UTILS_DIR),$(UTILS_PRINTF))

all: make_libft $(NAME_SRV) $(NAME_CLI)

make_libft:
	$(MAKE) -C $(LIBFT_DIR)

#$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
#	mkdir -p $(dir $@)
#	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

-include $(DEPS)
$(NAME_SRV): $(LIBFT) $(SRC_SRV)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_SRV) -L$(LIBFT_DIR) -lft -o $@

$(NAME_CLI):  $(LIBFT) $(SRC_CLI)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_CLI) -L$(LIBFT_DIR) -lft -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all, clean, fclean, re
