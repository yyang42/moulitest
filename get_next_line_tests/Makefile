NAME = get_next_line_tests
INCLUDES = -I . -I ../testframework
FLAGS = -Werror -Wall -Wextra
SOURCE = ../testframework/*.c ./tests/*.c main.c
tests ?= spec.c$$
ADD_TESTS = $(shell ls -1 tests | grep -e "$(tests)" | \
		sed -E "s/(.*)\.spec\.c/ut_add_test\(\&ut_test_\1, \\\\\"\1\\\\\"\);/g")
RENDU_PATH = $(shell grep GET_NEXT_LINE_PATH ../config.ini | cut -d '=' -f 2)
PROTOTYPES = $(shell ls -1 tests | grep -e "$(tests)" | sed -E "s/(.*)\.spec\.c/UT_TEST\(\1\);/g")
DEFINES = -D PROTOTYPES="$(PROTOTYPES)" -D ADD_TESTS="$(ADD_TESTS)" -D RENDU_PATH="\"$(RENDU_PATH)\""

all: $(NAME)
	@./$(NAME)

$(NAME):
	@make -k -C $(RENDU_PATH)/libft
	@gcc -g $(FLAGS) $(INCLUDES) $(DEFINES) $(SOURCE) $(RENDU_PATH)/libft/libft.a $(RENDU_PATH)/get_next_line.c -I $(RENDU_PATH) -I $(RENDU_PATH)/libft/includes -o $(NAME)

fclean:
	make -C $(RENDU_PATH)/libft fclean
	rm -f $(NAME)

re: fclean all
