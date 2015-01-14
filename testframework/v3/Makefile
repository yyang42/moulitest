NAME = libmt_framework.a
INCLUDES = -I includes
# SRCS = main.c **/*.c
SRCS = **/*.c
FLAGS = -Wall -Werror -Wextra -ggdb

all: clean
	gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	gcc $(NAME) main.c -I includes
	./a.out
