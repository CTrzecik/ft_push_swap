# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/24 16:56:54 by dibranco          #+#    #+#              #
#    Updated: 2026/11/20 17:38:49 by dibranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
MAKE = make
CFLAGS = -g -Wall -Wextra -Werror
LIBFT_DIR = $(PARENT_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFTDPRINTF_DIR = $(PARENT_DIR)ft_dprintf/
LIBFTDPRINTF = $(LIBFTDPRINTF_DIR)libftdprintf.a
SRCS = main.c push_swap_utils.c strategy_selector_utils.c error.c disorder.c \
	   rules_a.c rules_b.c rules_s.c algorithms.c parser.c \
	   simple_algo_utils.c medium_algo_utils.c complex_algo_utils.c benchmark.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTDPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBFTDPRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFTDPRINTF):
	$(MAKE) -C $(LIBFTDPRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBFTDPRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBFTDPRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
