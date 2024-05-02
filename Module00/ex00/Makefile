NAME	= megaphone

SRCS	= megaphone.cpp
OBJS    = $(SRCS:.cpp=.o)
CC		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS) $(OBJS)
	$(CC) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
