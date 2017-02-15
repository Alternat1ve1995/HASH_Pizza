NAME = PIZZA
FLAGS = -Wall -Wextra -Werror
SRC = expand.c main_test.c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -o pizza