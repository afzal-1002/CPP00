GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = megaphone

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN) Building $(NAME)...$(RESET)"
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "$(GREEN)Object files deleted.$(RESET)"

fclean: clean
	rm -f $(NAME)
	@echo "$(RED)Executable deleted.$(RESET)"

re: fclean all

.PHONY: all clean fclean re