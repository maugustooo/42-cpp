SRC = main.cpp Pmerge.cpp

NAME = PmergeMe

CC = c++ -Wall -Werror -Wextra -g -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)~

fclean: clean

re: fclean all