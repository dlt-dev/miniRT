# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/13 11:37:30 by jdelattr          #+#    #+#              #
#    Updated: 2026/02/21 15:26:33 by jdelattr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parsing

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	parsing.c \
		get_next_line.c \
		get_next_line_utils.c \
		libft_utils.c \
		print_test.c \
		free.c \
		check_value.c \
		split.c \
		param.c \
		utils_obj_list.c \
		init.c \
		pars_value.c \
		object.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
