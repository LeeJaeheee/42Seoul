# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 00:21:39 by jaeheele          #+#    #+#              #
#    Updated: 2023/03/26 01:06:32 by jaeheele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rc
RM = rm -f

SRCS = ft_printf.c\
		ft_printf_utils.c\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(AR) $@ $^

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
