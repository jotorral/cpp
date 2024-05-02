NAME = harlFilter 

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g
LDFLAGS = 
SRCS = main.cpp Harl.cpp
OBJ = $(SRCS:.cpp=.o)
CC = c++
RM = rm -f

all = $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

execute:
	./$(NAME) "DEBUG"

.PHONY: all clean fclean re execute
