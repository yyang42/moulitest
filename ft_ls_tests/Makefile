NAME = ft_ls_tests
INCLUDES = -I . -I ../testframework
FLAGS = -Werror -Wall -Wextra
SOURCE = ../testframework/*.c ./testsv2/*.c main_v2.c utils.c
tests ?= spec.c$$
ADD_TESTS = $(shell ls -1 testsv2 | grep -e "$(tests)" | sed -E "s/(.*)\.spec\.c/UT_ADD_TEST\(\1\);/g")
RENDU_PATH = $(shell grep FT_LS_PATH ../config.ini | cut -d '=' -f 2)
PROTOTYPES = $(shell ls -1 testsv2 | grep -e "$(tests)" | sed -E "s/(.*)\.spec\.c/UT_TEST\(\1\);/g")
DEFINES = -DPROTOTYPES="$(PROTOTYPES)" -DADD_TESTS="$(ADD_TESTS)" -DRENDU_PATH="\"$(RENDU_PATH)\""

all: $(NAME)
	@make -C $(RENDU_PATH) re
	@./a.out

$(NAME):
	@gcc -g $(FLAGS) $(INCLUDES) $(DEFINES) $(SOURCE)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
