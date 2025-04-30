# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhervoch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 15:39:54 by jhervoch          #+#    #+#              #
#    Updated: 2025/03/03 15:50:07 by jhervoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= megaphone
FLAGS 	= -Wall -Wextra -Werror -std=c++98
CC 		= c++

SRCS	= megaphone.cpp

OBJS	= $(SRCS:%.cpp=%.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

$(OBJS) : %.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re		: 
	make fclean --no-print-directory
	make all --no-print-directory

.PHONY : all clean fclean
