# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotorral <jotorral@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:58:26 by mwagner           #+#    #+#              #
#    Updated: 2024/01/10 13:17:34 by jotorral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN 		:= \033[0;32m
RED 		:= \033[0;31m
LIGHT_BLUE	:= \033[0;36m
RESET_COL 	:= \033[0m

NAME 		:= sed
CC 			:= c++
CXXFLAGS 	:= -Wall -Werror -Wextra -std=c++98 -g
SRC 		:= $(wildcard *.cpp)
OBJS		:= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)$(NAME) *.o files compiled!$(RESET_COL)"
	@echo "$(LIGHT_BLUE)Linking the executable $(NAME)...$(RESET_COL)"
	$(CC) $^ -o $@
	@echo "$(GREEN)$(NAME) executable file created!$(RESET_COL)"

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
