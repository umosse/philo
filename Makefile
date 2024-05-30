# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umosse <umosse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 14:37:23 by umosse            #+#    #+#              #
#    Updated: 2024/05/29 14:37:41 by umosse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 
CC = cc
INCLUDE = 
SRCS = 
SRCSBONUS = 
OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(SRCSBONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

all: $(NAME)

bonus: $(OBJS) $(OBJSBONUS)
	ar r $(NAME) $(OBJS) $(OBJSBONUS)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re