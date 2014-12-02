NAME = ft_ls_tests
INCLUDES = -I . -I ../testframework
FLAGS = -Werror -Wall -Wextra -g
SOURCE = ../testframework/*.c ./required/*.c main_v2.c utils.c
tests ?= spec.c
PROTOTYPES = $(shell ls -1 required | grep "$(tests)" | sed -E "s/(.*)\.spec\.c/UT_TEST\(\1\);/g")
ADD_TESTS = $(shell ls -1 required | grep "$(tests)" | sed -E "s/(.*)\.spec\.c/UT_ADD_TEST\(\1\);/g")
RENDU_PATH = $(shell grep FT_LS_PATH ../config.ini | cut -d '=' -f 2)
DEFINES = -DPROTOTYPES="$(PROTOTYPES)" -DADD_TESTS="$(ADD_TESTS)" -DRENDU_PATH="\"$(RENDU_PATH)\""

all: $(NAME)
	@./a.out

$(NAME):
	@echo "macro PROTOTYPES: $(PROTOTYPES)"
	@echo "macro ADD_TESTS: $(ADD_TESTS)"
	@gcc -g $(FLAGS) $(INCLUDES) $(DEFINES) $(SOURCE)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
