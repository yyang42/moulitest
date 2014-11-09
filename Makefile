.PHONY: all, clean, fclean, re

NAME = unit_test
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -I./..
LDFLAGS = -L./.. -lft
SOURCE = main.c unit_test.c
OBJ = $(SOURCE:.c=.o)
BUILD = main.build.c

all : $(NAME)


$(NAME): $(OBJ) make_libft
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(BUILD)

test: test_unit test_qperez test_moulinator

test_unit: re
	./unit_test

test_qperez:
	rm -f ./a.out
	gcc test_qperez.c ../*.c -I../ && ./a.out

test_moulinator:
	make re -C ../unit_test_moulinator

test_custom:
	make -C ../
	$(CC) $(CFLAGS) $(LDFLAGS) main.build.c unit_test.c -o $(NAME)
	./unit_test

test_yyang:
	echo "#define EXTRA_YYANG\n" | cat - main.c > main.build.c
	make test_custom

re: fclean all

make_libft:
	make -C ../
