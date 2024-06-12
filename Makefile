# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umosse <umosse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 14:37:23 by umosse            #+#    #+#              #
#    Updated: 2024/06/12 16:43:18 by umosse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
INCLUDE = philo.h
SRCS = data.c end.c parsing.c philo.c utils.c utils2.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

all: $(NAME)

bonus: $(OBJS)
	ar r $(NAME) $(OBJS)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re