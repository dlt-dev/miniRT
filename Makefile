# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 12:34:16 by cybourge          #+#    #+#              #
#    Updated: 2026/04/29 12:50:56 by cybourge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ls -1 src | sed ':a;N;$!ba;s/\n/\\\n/g'

CC = cc
C_FLAGS = -Wall -Wextra -Werror -MMD -g
#-o1

RED = \033[31;1;3m
GREEN = \033[32;1;3m
YEL = \033[33;1;3m
CYAN = \033[36;1;3m
VIOLET = \033[1;35m
BLUE = \033[1;34m
RESET = \033[m

COMP_LIBS = -I$(MLXDIR) -I/usr/include
LINK_LIBS = -L$(MLXDIR) -lmlx_Linux -lXext -lX11 -lm -lz

#$(notdir $(wildcard src/*.c))

MAKE += --silent --no-print-directory

MLXDIR  = minilibx-linux


LIB_NAME = libmlx_Linux.a
LIB_BIN = $(MLXDIR)/libmlx_Linux.a
MK_MLX = $(MAKE) --silent -C$(MLXDIR) 2>/dev/null



OBJS_DIR = obj
SRCS_DIR = src
DEPS_DIR = $(OBJS_DIR)
INCS_DIR = inc


SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

NAME = minirt


all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(C_FLAGS) -I$(INCS_DIR) $(COMP_LIBS) -c $< -o $@


$(MLXDIR):
	@printf "$(CYAN)Cloning MiniLibX...$(RESET)\n"
	@if [ ! -d "$(MLXDIR)" ]; then \
		git clone https://github.com/42paris/minilibx-linux.git $(MLXDIR); fi
	

$(NAME): $(MLXDIR) $(OBJS) $(LIB_BIN)
	@printf "$(BLUE)Linking files at light speed...$(RESET)\n"
	@$(CC) $(C_FLAGS) $(OBJS) $(LINK_LIBS) -o $@
	@printf "$(VIOLET)The journey is over!$(RESET)\n"

$(LIB_BIN): $(MLXDIR)
	@printf "$(CYAN)Building MiniLibX...$(RESET)\n"
	@$(MAKE) -C $(MLXDIR)
	@printf "$(GREEN)MiniLibX ready!$(RESET)\n"

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./minirt hello.rt

clean:
	rm -rf $(OBJS_DIR)
	@if [ -d "$(MLXDIR)" ]; then $(MAKE) clean -C $(MLXDIR); fi

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLXDIR)
	
re: fclean
	@$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
