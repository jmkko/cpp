NAME    = PhoneBook
CC      = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98


SRCS = phonebook.cpp

OBJS = $(SRCS:%.cpp:%.o)


all     : $(NAME)

$(NAME) : $(OBJS)
    $(CC) $(FLAGS) $^ -o $@

$(OBJS) : %.o : %.cpp
    $(CC) $(FLAGS) -c $< -o $@

clean 	:
	rm -rf $(OBJS)

fclean :
	clean
	rm -rf $(OBJS)

re 		:
	fclean
	rm -rf $(NAME)

.PHONY : all clean fclean re
