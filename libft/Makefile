.PHONY: help, all, clean, fclean, re, test, suite_moulinator, suite_qperez

NAME = unit_test
RENDU_PATH = $(shell awk -F "=" '/LIBFT_PATH/ {print $$2}' ../config)
FRAMEWORK_PATH = ../_testframework
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -I$(RENDU_PATH) -I$(FRAMEWORK_PATH)
LDFLAGS = -L$(RENDU_PATH) -lft
SOURCE = main.c $(FRAMEWORK_PATH)/testframework.c
OBJ = main.o testframework.o
BUILD = main.build.c

all: $(NAME)

$(NAME): make_libft
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(BUILD)
	rm -rf testsuite_moulinator/*.o testsuite_moulinator/libft.so

test: make_libft re test_bonus suite_qperez suite_moulinator

test_unit: re
	./$(NAME)

suite_qperez:
	rm -f ./a.out
	gcc testsuite_qperez/main.c $(RENDU_PATH)/*.c -I$(RENDU_PATH) && ./a.out

suite_moulinator:
	make re -C ./testsuite_moulinator

test_custom: make_libft
	$(CC) $(CFLAGS) $(LDFLAGS) main.build.c ../_testframework/testframework.c -o $(NAME)
	./$(NAME)

test_yyang:
	echo "#define EXTRA_YYANG\n#define PART1\n#define PART2\n#define BONUS\n" > main.build.c
	cat main.c >> main.build.c
	make test_custom

test_juschaef:
	echo "#define EXTRA_JUSCHAEF\n#define PART1\n#define PART2\n#define BONUS\n" > main.build.c
	cat main.c >> main.build.c
	make test_custom

test_mvo:
	echo "#define EXTRA_MVO\n#define PART1\n#define PART2\n#define BONUS\n" > main.build.c
	cat main.c >> main.build.c
	make test_custom

test_part1:
	echo "#define PART1\n" > main.build.c
	cat main.c >> main.build.c
	make test_custom

test_part2:
	echo "#define PART1\n#define PART2" > main.build.c
	cat main.c >> main.build.c
	make test_custom

test_bonus:
	echo "#define PART1\n#define PART2\n#define BONUS\n" > main.build.c
	cat main.c >> main.build.c
	make test_custom

re: fclean all

make_libft:
	make re -C $(RENDU_PATH)
