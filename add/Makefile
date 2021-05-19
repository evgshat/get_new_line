# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 16:35:40 by lcharlet          #+#    #+#              #
#    Updated: 2021/05/12 17:34:51 by lcharlet         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS :=


OBJS = $(SRCS:.c=.o)

NAME = libft.a

CFLAGS = -Werror -Wall -Wextra -c
CC = gcc

RM = rm -rf

HEADER = -I libft.h

.c.o:
	$(CC) $(CFLAGS) $< ${HEADER} -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
