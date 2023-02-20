# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 16:18:33 by mpalkov           #+#    #+#              #
#    Updated: 2023/02/09 14:11:03 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLI	=	client

NAME_SRV	=	server

#---- FILES ----

SRC_CL		=	client.c

SRC_SRV		=	server.c

#---- DIRECTORIES ----

LIBFT_DIR	=	utils/libft

OBJ_DIR		=	obj/

INCL_DIR	=	includes/

SRC_DIR		=	src/

UTILS_DIR	=	utils/

#---- COMMANDS ----

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra -MMD -MP -MT $@

RM			=	rm -f

CP			=	cp -f

#---- RULES ----

LIBFT		=	$(LIBFT_DIR)libft.a

OBJ			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

INCLUDE		=	-I$(INCL_DIR)

DEPS		=	$(addsuffix .d,$(basename $(OBJ)))

UTILS		=	$(addprefix $(UTILS_DIR),$(UTILS_PRINTF))

SRCS		+=	$(addprefix $(SRC_DIR),$(SRC_PRINTF))

SRCS		+=	$(addprefix $(UTILS_DIR),$(UTILS_PRINTF))

all: make_libft $(NAME_SRV) $(NAME_CLI)

make_libft:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

-include $(DEPS)
$(NAME): $(OBJ) $(LIBFT) $(INCL_DIR)
	$(CP) $(LIBFT_DIR) ./$(NAME)
	ar -crs $(NAME) $(OBJ)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
