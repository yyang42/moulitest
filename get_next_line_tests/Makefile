NAME = get_next_line_tests
RENDU_PATH = $(shell grep GET_NEXT_LINE_PATH ../config.ini | cut -d '=' -f 2)
INCLUDES = -I ../testframework/v3/includes -I . -I$(RENDU_PATH) -I$(RENDU_PATH)/libft/includes
FLAGS = -Werror -Wall -Wextra
SOURCE = ./tests/*.spec.c main.c $(RENDU_PATH)/get_next_line.c $(RENDU_PATH)/libft/libft.a
pattern ?= spec.c$$
ADD_TESTS = $(shell ls -1 tests | grep -e "$(pattern)" | \
		sed -E "s/(.*)\.spec\.c/MT_ADD_SUITE\(mt, \1, suite_\1);/g")
PROTOTYPES = $(shell ls -1 tests | grep -e "$(pattern)" | sed -E "s/(.*)\.spec\.c/MT_ADD_PROTO\(\1\);/g")
DEFINES = -DPROTOTYPES="$(PROTOTYPES)" -DADD_TESTS="$(ADD_TESTS)" -DRENDU_PATH="\"$(RENDU_PATH)\""


all: project
	gcc $(FLAGS) $(INCLUDES) $(DEFINES) $(SOURCE) -L../testframework/v3 -lmt_framework -L$(RENDU_PATH)  -o $(NAME)
	./$(NAME)


project:
	make -k -C ../testframework/v3/

$(NAME): project
	gcc $(FLAGS) $(INCLUDES) $(DEFINES) $(SOURCE) -L../testframework/v3 -lmt_framework -L$(RENDU_PATH)  -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	make -k -C ../testframework/v3/ fclean
	rm -f $(NAME)

re: clean fclean all project
