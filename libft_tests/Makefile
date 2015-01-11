#===============================================================================
# CUSTOM
#===============================================================================
NAME = libft_tests
CONFIG_RENDU_PATH_KEY = LIBFT_PATH
LIBS = -lft -L$(RENDU_PATH)
POST_PATTERN = "^01_part2"
#===============================================================================
# COMMON
#===============================================================================
RENDU_PATH = $(shell grep $(CONFIG_RENDU_PATH_KEY) ../config.ini | cut -d '=' -f 2)
INCLUDES = -I ../testframework/v3/includes -I . -I $(RENDU_PATH)/includes
FLAGS = -g -Werror -Wextra -Wall
SOURCE = ./tests/*.spec.c main.c utils.c
pattern ?= spec.c$$
TEST_FILES = ls -1 tests | grep -e "$(pattern)" | grep -e "$(POST_PATTERN)"
ADD_TESTS = $(shell $(TEST_FILES) | sed -E "s/(.*)\.spec\.c/MT_ADD_SUITE\(mt, \1, suite_\1);/g")
PROTOTYPES = $(shell $(TEST_FILES) | sed -E "s/(.*)\.spec\.c/MT_ADD_PROTO\(\1\);/g")
DEFINES = -DPROTOTYPES="$(PROTOTYPES)" -DADD_TESTS="$(ADD_TESTS)" -DRENDU_PATH="\"$(RENDU_PATH)\""
FRAMEWORK_LIB = -L../testframework/v3 -lmt_framework

all:
	@echo "Usage:"
	@echo "\tmake part1"
	@echo "\tmake part2\t--> Also runs part1"
	@echo "\tmake bonus\t--> Also runs part1 and part2"

exec_tests:
	make re -k -C $(RENDU_PATH)
	make -k -C ../testframework/v3/
	gcc $(FLAGS) $(INCLUDES) $(DEFINES) $(SOURCE) $(LIBS) $(FRAMEWORK_LIB) -o $(NAME)
	./$(NAME)

part1_init:
	$(eval POST_PATTERN = "^00_part1")
part1: part1_init exec_tests

part2_init:
	$(eval POST_PATTERN = "^01_part2")
part2: part2_init exec_tests

bonus_init:
	$(eval POST_PATTERN = "^02_bonus")
bonus: bonus_init exec_tests

all_init:
	$(eval POST_PATTERN = .*)

clean:
	rm -f $(OBJECTS)

fclean: clean
	make -k -C $(RENDU_PATH) fclean
	make -k -C ../testframework/v3/ fclean
	rm -f $(NAME)

re: clean fclean all project
