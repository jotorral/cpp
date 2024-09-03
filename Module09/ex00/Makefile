NAME = btc

SRCS = $(wildcard *.cpp)
OBJ = $(SRCS:.cpp=.o)
CC = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g -O0

RGB_COLOUR 		:= \033[38;2;0;255;255m
RGB_BACKGROUND	:= \033[48;2;0;255;255m
RESET_COL 		:= \033[0m

all: $(NAME)

%.o: %.cpp
	$(CC) -c $(CXXFLAGS) $< -o $@

$(NAME): $(OBJ)
	@echo "$(RGB_COLOUR)            *.o files created! $(RESET_COL)"
	$(CC) $(OBJ) -o $(NAME)
	@echo "$(RGB_BACKGROUND)            $(NAME) executable created! $(RESET_COL)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

execute:
#		valgrind -s --leak-check=full ./$(NAME)
	./$(NAME) "input2.txt"
.PHONY: all clean fclean re execute
