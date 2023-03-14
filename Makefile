# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 16:18:33 by mpalkov           #+#    #+#              #
#    Updated: 2023/03/14 15:56:07 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLI	:=	client

NAME_SRV	:=	server

NAME_C_BNS	:=	client_bonus

NAME_S_BNS	:=	server_bonus

#-------------------------------------------------------------------------------
#		COLORS

DEFCOLOR	:=	\033[0;39m
GRAY		:=	\033[0;90m
RED			:=	\033[0;91m
ORANGE		:=	\033[0;33m
GREEN		:=	\033[0;92m
YELLOW		:=	\033[0;93m
BLUE		:=	\033[0;94m
MAGENTA		:=	\033[0;95m
CYAN		:=	\033[0;96m
WHITE		:=	\033[0;97m

#-------------------------------------------------------------------------------
#---- FILES ----

SRC_CLI		:=	client.c

SRC_SRV		:=	server.c \
				server_utils.c \
				server_utils2.c

SRC_C_BNS	:=	bonus/client_bonus.c

SRC_S_BNS	:=	bonus/server_bonus.c \
				bonus/server_utils_bonus.c \
				bonus/server_utils2_bonus.c

SRCS		+=	$(SRC_CLI) $(SRC_SRV)

SRCS_BNS	+=	$(SRC_C_BNS) $(SRC_S_BNS)

#-------------------------------------------------------------------------------
#---- DIRECTORIES ----

LIBFT_DIR	:=	utils/libft/

OBJ_DIR		:=	.obj/

SRC_DIR		:=	src/

UTILS_DIR	:=	utils/

#-------------------------------------------------------------------------------
#---- COMMANDS ----

CC			:=	cc

CFLAGS		+=	-MMD -MP -MT $@

CFLAGS		+=	-Wall -Werror -Wextra

RM			:=	rm -f

CP			:=	cp -f

MAKEFLAGS	+=	--no-print-directory

#-------------------------------------------------------------------------------
#---- RULES ----

LIBFT		=	$(LIBFT_DIR)libft.a

OBJ_SRV		=	$(addprefix $(OBJ_DIR), $(SRC_SRV:.c=.o))

OBJ_CLI		=	$(addprefix $(OBJ_DIR), $(SRC_CLI:.c=.o))

OBJ			=	$(OBJ_SRV) $(OBJ_CLI)

DEPS		=	$(addsuffix .d,$(basename $(OBJ)))

OBJ_S_BNS	=	$(addprefix $(OBJ_DIR), $(SRC_S_BNS:.c=.o))

OBJ_C_BNS	=	$(addprefix $(OBJ_DIR), $(SRC_C_BNS:.c=.o))

OBJ_BNS		=	$(OBJ_S_BNS) $(OBJ_C_BNS)

DEPS_BNS	=	$(addsuffix .d,$(basename $(OBJ_BNS)))

INCLUDE		:=	-I./utils/libft/includes/ -I./utils/libft/ -I./includes/

UTILS		=	$(addprefix $(UTILS_DIR),$(UTILS_PRINTF))

all: make_libft $(NAME_SRV) $(NAME_CLI)

bonus: make_libft $(NAME_C_BNS) $(NAME_S_BNS)

make_libft:
	@echo "$(GREEN)	Calling Libft make $(DEFCOLOR)"
	$(MAKE) -Cs $(LIBFT_DIR)

#$(NAME_SRV): $(LIBFT) $(SRC_SRV)

$(OBJ_DIR)%.o: %.c Makefile
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	@echo "$(GREEN)	Compiling: $< -> $@ $(DEFCOLOR)"


-include $(DEPS)

$(NAME_SRV): $(OBJ_SRV) $(LIBFT)
	@echo "$(GREEN)	Creating binary: $@ $(DEFCOLOR)"
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ_SRV) -L$(LIBFT_DIR) -lft -o $@

#$(NAME_CLI): $(LIBFT) $(SRC_CLI)

$(NAME_CLI): $(OBJ_CLI) $(LIBFT)
	@echo "$(GREEN)	Creating binary: $@ $(DEFCOLOR)"
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ_CLI) -L$(LIBFT_DIR) -lft -o $@


-include $(DEPS_BNS)

$(NAME_S_BNS): $(OBJ_S_BNS)
	@echo "$(GREEN)	Creating binary: $@ $(DEFCOLOR)"
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ_S_BNS) -L$(LIBFT_DIR) -lft -o $@

#$(NAME_CLI): $(LIBFT) $(SRC_CLI)

$(NAME_C_BNS): $(OBJ_C_BNS)
	@echo "$(GREEN)	Creating binary: $@ $(DEFCOLOR)"
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ_C_BNS) -L$(LIBFT_DIR) -lft -o $@

clean:
	@echo "$(ORANGE)	Cleaning residual .o and .d files$(DEFCOLOR)"
#	$(MAKE) clean -sC $(LIBFT_DIR)
	$(RM) -r $(OBJ_DIR)
	$(RM) *.d

fclean: clean
	@echo "$(ORANGE)	Cleaning main binary files$(DEFCOLOR)"
	$(RM) $(NAME_CLI) $(NAME_SRV) $(NAME_C_BNS) $(NAME_S_BNS)
#	$(MAKE) fclean -C $(LIBFT_DIR)

re:
	$(MAKE) fclean 
	$(MAKE) all 

.PHONY: all, clean, fclean, re 
