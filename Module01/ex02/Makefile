VAL	= valgrind -s --leak-check=full --show-leak-kinds=all
RUN	= ./hi

NAME = hi

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)
CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all

val:
		$(VAL) $(RUN)

execute:
		./$(NAME)

.PHONY: clean fclean re all val execute
