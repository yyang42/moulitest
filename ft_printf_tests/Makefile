NAME = ft_printf_test
INCLUDES = -I . -I ../testframework
FLAGS = 
SOURCE = ../testframework/*.c ./tests/*.c main.c
tests ?= spec.c$$
ADD_TESTS = $(shell ls -1 tests | grep -e "$(tests)" | \
		sed -E "s/(.*)\.spec\.c/ut_add_test\(\&ut_test_\1, \\\\\"\1\\\\\"\);/g")
RENDU_PATH = $(shell grep FT_PRINTF_PATH ../config.ini | cut -d '=' -f 2)
PROTOTYPES = $(shell ls -1 tests | grep -e "$(tests)" | sed -E "s/(.*)\.spec\.c/UT_TEST\(\1\);/g")
DEFINES = -DPROTOTYPES="$(PROTOTYPES)" -DADD_TESTS="$(ADD_TESTS)" -DRENDU_PATH="\"$(RENDU_PATH)\""

all: $(NAME)
	@./$(NAME)

project:
	@make re -k -C $(RENDU_PATH)

$(NAME): project
	@gcc -g $(FLAGS) $(INCLUDES) $(DEFINES) $(SOURCE) -lftprintf -L $(RENDU_PATH) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	@make -C $(RENDU_PATH) fclean
	rm -f $(NAME)

re: clean fclean all project
