# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 17:12:19 by sangmlee          #+#    #+#              #
#    Updated: 2022/01/10 21:31:46 by sangmlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				str_utils.c \
				transform.c \
				transform_utils.c \
				transform_logic.c

OBJS		=	$(SRCS:.c=.o)

INCS		=	ft_printf.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

AR          =   ar rc

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

test:
	$(CC) $(CFLAGS) $(SRCS)	

re: fclean all
