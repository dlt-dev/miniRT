# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 12:34:16 by cybourge          #+#    #+#              #
#    Updated: 2026/03/26 09:26:01 by cybourge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ls -1 src | sed ':a;N;$!ba;s/\n/\\\n/g'

CC = cc
C_FLAGS = -Wall -Wextra -Werror -MMD -o1

RED = \033[31;1;3m
GREEN = \033[32;1;3m
YEL = \033[33;1;3m
CYAN = \033[36;1;3m
VIOLET = \033[1;35m
BLUE = \033[1;34m
RESET = \033[m

COMP_LIBS = -I/usr/include -I$(LIB_DIR)
LINK_LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib \
			-L$(LIB_DIR) -lmlx_Linux \
			-Imlx_linux -lXext -lX11 -lm -lz

SRCS_FILES = test_v3.c\
v3_add.c\
v3_div.c\
v3_dot.c\
v3_eql.c\
v3_inv.c\
v3_len.c\
v3_lsq.c\
v3_mul.c\
v3_sub.c\
v3_uni.c\
v3_xpr.c

OBJS_FILES = ${SRCS_FILES:.c=.o}
DEPS_FILES = ${SRCS_FILES:.c=.d}
OBJS_DIR = obj
SRCS_DIR = src
DEPS_DIR = $(OBJS_DIR)
INCS_DIR = inc
LIB_DIR = minilibx-linux

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))
DEPS = $(addprefix $(DEPS_DIR)/, $(DEPS_FILES))

NAME = minirt
LIB_NAME = libmlx_Linux.a
LIB_BIN = $(addprefix $(LIB_DIR)/, $(LIB_NAME))

MAKE += --silent --no-print-directory

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(C_FLAGS) $(COMP_LIBS) -I$(INCS_DIR) -c $< -o $@
	

$(NAME): $(OBJS) $(LIB_BIN)
	@echo "$(BLUE)Linking files at light speed...$(RESET)"
	@$(CC) $(C_FLAGS) $(OBJS) $(LINK_LIBS) -o $@
	@echo "$(VIOLET)The journey is over! Look out the window!$(RESET)"

$(LIB_BIN):
	@echo "$(CYAN)Building MiniLibx...$(RESET)"
	@$(MAKE) --silent -C $(LIB_DIR) 2> /dev/null
	@echo "$(CYAN)MiniLibx built!$(RESET)"

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(DEPS_DIR)
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	@$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
