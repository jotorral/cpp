VAL	= valgrind -s --leak-check=full --show-leak-kinds=all

RUN	= ./Zombie

NAME = Zombie

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJS = $(SRCS:.cpp=.o)
CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98# -g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)

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
