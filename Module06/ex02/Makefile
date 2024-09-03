NAME = a.out

SRCS = $(wildcard *.cpp)
OBJ = $(SRCS:.cpp=.o)
CC = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g

RGB_COLOUR 		:= \033[38;2;0;255;255m
RGB_BACKGROUND	:= \033[48;2;0;255;255m
RESET_COL 		:= \033[0m

all = $(NAME)

$(NAME): $(OBJ)
	@echo "$(RGB_COLOUR)            *.o files created! $(RESET_COL)"
	$(CC) $(OBJ) -o $(NAME)
	@echo "$(RGB_BACKGROUND)            $(NAME) executable created! $(RESET_COL)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

execute:
		valgrind -s --leak-check=full ./$(NAME)

.PHONY: all clean fclean re execute
