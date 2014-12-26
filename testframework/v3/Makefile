NAME = mt_framework.a
INCLUDES = -I includes
# SRCS = main.c **/*.c
SRCS = **/*.c
FLAGS = -Wall -Werror -Wextra -g --std=c99

all:
	gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all