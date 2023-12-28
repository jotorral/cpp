VAL	= valgrind -s --leak-check=full --show-leak-kinds=all
RUN	= ./moar_brainz

NAME = moar_brainz

SRCS = main.cpp Zombie.cpp zombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)
CC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98# -g3 -fsanitize=address

all: $(NAME)

$(NAME): $(SRCS) $(OBJS)
		$(CC) $(CFLAG) $(SRCS) -o $(NAME)

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
