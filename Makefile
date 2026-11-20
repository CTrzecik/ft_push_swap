# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/24 16:56:54 by dibranco          #+#    #+#              #
#    Updated: 2026/11/18 08:40:41 by dibranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT_DIR = $(PARENT_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFTPRINTF_DIR = $(PARENT_DIR)ft_printf/
LIBFTPRINTF = $(LIBFTPRINTF_DIR)libftprintf.a
SRCS = main.c push_swap_utils.c strategy_selector_utils.c error.c disorder.c rules_a.c rules_b.c rules_s.c algorithms.c medium_utils.c parser.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBFTPRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
