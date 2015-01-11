NAME = get_next_line_tests
# INCLUDES = -I . -I ../testframework/v3/includes
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
	# make re -k -C $(RENDU_PATH)

$(NAME): project
	gcc $(FLAGS) $(INCLUDES) $(DEFINES) $(SOURCE) -L../testframework/v3 -lmt_framework -L$(RENDU_PATH)  -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	make -k -C $(RENDU_PATH) fclean
	make -k -C ../testframework/v3/ fclean
	rm -f $(NAME)

re: clean fclean all project


# NAME = get_next_line_tests
# INCLUDES = -I . -I ../testframework/v2
# FLAGS = -Werror -Wall -Wextra
# SOURCE = ../testframework/v2/*.c ./tests/*.c main.c
# tests ?= spec.c$$
# ADD_TESTS = $(shell ls -1 tests | grep -e "$(tests)" | \
# 		sed -E "s/(.*)\.spec\.c/ut_add_test\(\&ut_test_\1, \\\\\"\1\\\\\"\);/g")
# RENDU_PATH = $(shell grep GET_NEXT_LINE_PATH ../config.ini | cut -d '=' -f 2)
# PROTOTYPES = $(shell ls -1 tests | grep -e "$(tests)" | sed -E "s/(.*)\.spec\.c/UT_TEST\(\1\);/g")
# DEFINES = -D PROTOTYPES="$(PROTOTYPES)" -D ADD_TESTS="$(ADD_TESTS)" -D RENDU_PATH="\"$(RENDU_PATH)\""

# all: $(NAME)
# 	@./$(NAME)

# $(NAME):
# 	@make -k -C $(RENDU_PATH)/libft
# 	@gcc -g $(FLAGS) $(INCLUDES) $(DEFINES) $(SOURCE) $(RENDU_PATH)/libft/libft.a $(RENDU_PATH)/get_next_line.c -I $(RENDU_PATH) -I $(RENDU_PATH)/libft/includes -o $(NAME)

# fclean:
# 	make -C $(RENDU_PATH)/libft fclean
# 	rm -f $(NAME)

# re: fclean all


