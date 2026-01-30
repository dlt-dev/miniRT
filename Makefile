# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 12:34:16 by cybourge          #+#    #+#              #
#    Updated: 2026/01/30 11:21:33 by cybourge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ls -1 src | sed ':a;N;$!ba;s/\n/\\\n/g'

CC = cc
C_FLAGS = -Wall -Wextra -Werror -MMD -o1

COMP_LIBS = -I/usr/include -I$(LIB_DIR)
LINK_LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib \
			-L$(LIB_DIR) -lmlx_Linux \
			-Imlx_linux -lXext -lX11 -lm -lz 

SRCS_FILES = close_display.c\
free_mlx_data.c\
ft_memset.c\
handle_keypress.c\
handle_x_buton.c\
img_pix_put.c\
init_mlx_data.c\
minirt.c
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

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(C_FLAGS) $(COMP_LIBS) -I$(INCS_DIR) -c $< -o $@

$(NAME): $(OBJS) $(LIB_BIN)
	$(CC) $(C_FLAGS) $(OBJS) $(LINK_LIBS) -o $@

$(LIB_BIN):
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(DEPS_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
