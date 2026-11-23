# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/24 16:56:54 by dibranco          #+#    #+#              #
#    Updated: 2026/11/23 14:41:52 by dibranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftdprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs
HEADER = ft_dprintf.h
SRCS = ft_dprintf.c ft_dprintf_utils.c format_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
