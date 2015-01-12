NAME = ft_ls_test
# INCLUDES = -I . -I ../testframework/v3/includes
INCLUDES = -I ../testframework/v3/includes -I .
FLAGS_DISABLE = -Wno-format -Wno-format-extra-args
FLAGS = -ggdb -Werror -Wextra -Wall -p $(FLAGS_DISABLE)
SOURCE = ./tests/*.spec.c main.c utils.c
tests ?= spec.c$$
ADD_TESTS = $(shell ls -1 tests | grep -e "$(tests)" | \
		sed -E "s/(.*)\.spec\.c/MT_ADD_SUITE\(mt, \1, suite_\1);/g")
RENDU_PATH = $(shell grep FT_LS_PATH ../config.ini | cut -d '=' -f 2)
PROTOTYPES = $(shell ls -1 tests | grep -e "$(tests)" | sed -E "s/(.*)\.spec\.c/MT_ADD_PROTO\(\1\);/g")
DEFINES = -DPROTOTYPES="$(PROTOTYPES)" -DADD_TESTS="$(ADD_TESTS)" -DRENDU_PATH="\"$(RENDU_PATH)\""

all: $(NAME)
	./$(NAME)

project:
	make re -k -C $(RENDU_PATH)
	make -k -C ../testframework/v3/

$(NAME): project
	gcc $(FLAGS) $(INCLUDES) $(DEFINES) $(SOURCE) -L../testframework/v3 -lmt_framework -L$(RENDU_PATH)  -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	make -k -C $(RENDU_PATH) fclean
	make -k -C ../testframework/v3/ fclean
	rm -f $(NAME)

re: clean fclean all project
