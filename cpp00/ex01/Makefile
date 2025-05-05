NAME     = PhoneBook
CC       = c++
FLAGS    = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I.

OBJS_DIR = obj

SRCS = main.cpp Contact.cpp PhoneBook.cpp

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $^ -o $@

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean	:
	rm -rf $(OBJS_DIR)

fclean	: clean
	rm -rf $(NAME)

re	:
	make fclean --no-print-directory
	make all --no-print-directory

.PHONY : all clean fclean
