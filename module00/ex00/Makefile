SRC = megaphone.cpp

NAME = megaphone

CC = c++ -Wall -Werror -Wextra  -std=c++98
all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
