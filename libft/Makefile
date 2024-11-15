# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 17:50:29 by yanshen           #+#    #+#              #
#    Updated: 2024/11/13 23:13:24 by yanshen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
TEST	= test
SRC	= src

SRCS	= $(wildcard $(SRC)/*.c)
OBJS	= $(SRCS:.c=.o) 
CFLAGS	= -Wall -Wextra -Werror

all	: $(NAME)
com : $(TEST)

$(TEST)	: $(OBJS)
	cc $(OBJS) -o $(TEST)

$(OBJ)/%.o : $(SRC)/%.c libft.h
	cc $(CFLAGS) -I libft.h -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re