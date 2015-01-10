#===============================================================================
# CUSTOM
#===============================================================================
NAME = libft_tests
CONFIG_RENDU_PATH_KEY = LIBFT_PATH
LIBS = -lft -L$(RENDU_PATH)
#===============================================================================
# COMMON
#===============================================================================
RENDU_PATH = $(shell grep $(CONFIG_RENDU_PATH_KEY) ../config.ini | cut -d '=' -f 2)
INCLUDES = -I ../testframework/v3/includes -I . -I $(RENDU_PATH)/includes
FLAGS = -g -Werror -Wextra -Wall
SOURCE = ./tests/*.spec.c main.c utils.c
tests ?= spec.c$$
ADD_TESTS = $(shell ls -1 tests | grep -e "$(tests)" | \
		sed -E "s/(.*)\.spec\.c/MT_ADD_SUITE\(mt, \1, suite_\1);/g")
PROTOTYPES = $(shell ls -1 tests | grep -e "$(tests)" | sed -E "s/(.*)\.spec\.c/MT_ADD_PROTO\(\1\);/g")
DEFINES = -DPROTOTYPES="$(PROTOTYPES)" -DADD_TESTS="$(ADD_TESTS)" -DRENDU_PATH="\"$(RENDU_PATH)\""
FRAMEWORK_LIB = -L../testframework/v3 -lmt_framework

all: $(NAME)
	./$(NAME)

project:
	make re -k -C $(RENDU_PATH)
	make -k -C ../testframework/v3/

$(NAME): project
	gcc $(FLAGS) $(INCLUDES) $(DEFINES) $(SOURCE) $(LIBS) $(FRAMEWORK_LIB) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	make -k -C $(RENDU_PATH) fclean
	make -k -C ../testframework/v3/ fclean
	rm -f $(NAME)

re: clean fclean all project
