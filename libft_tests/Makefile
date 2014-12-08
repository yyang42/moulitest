NAME = libft_test
FLAGS = -Werror -Wall -Wextra
SOURCE = ../testframework/*.c main.c ./part1/*.c utils.c
tests ?= spec.c$$
RENDU_PATH = $(shell grep LIBFT_PATH ../config.ini | cut -d '=' -f 2)
PROTOTYPES = $(shell ls -1 part1 part2 bonus extra | grep -v ':' | sed -E "s/(.*)\.spec\.c/UT_TEST\(\1\);/g")
DEFINES = -DPROTOTYPES="$(PROTOTYPES)" -DRENDU_PATH="\"$(RENDU_PATH)\""
INCLUDES = -I$(RENDU_PATH) -I ../testframework -I.
PARTS = -DPART1
PARTS_DIRS = part1

all:
	@echo "\nUsage:\n\tmake part1\n\tmake part2\t--> Also runs part1"
	@echo "\tmake bonus\t--> Also runs part1 and part2"
	@echo "\tmake extra\t--> Also runs part1, part2 and bonus (You need to set extra tests in config.ini)"
	@echo "\nCorrection:\n\tmake check_forbidden_fn\n"

part2_def:
	$(eval PARTS += -DPART2)
	$(eval SOURCE += ./part2/*.c)

part2: part2_def part1

bonus_def: part2_def
	$(eval PARTS += -DBONUS)
	$(eval SOURCE += ./bonus/*.c)

bonus: bonus_def part1

extra_def: bonus_def
	$(eval PARTS += -DEXTRA)
	$(eval SOURCE += ./extra/*.c)

extra: extra_def part1

project:
	@make -C $(RENDU_PATH)

part1: project
	$(eval ADD_TESTS = $(shell ls -1 $(PARTS_DIRS) | grep -v ':' | grep -e "$(tests)" | sed -E 's/(.*)\.spec\.c/ut_add_test\(\&ut_test_\1, \\\"\1\\\"\);/'))
	$(eval DEFINES += -DADD_TESTS="$(ADD_TESTS)")
	@gcc -g $(FLAGS) $(INCLUDES) $(DEFINES) $(PARTS) -lft -L$(RENDU_PATH) $(SOURCE) -o $(NAME)
	@./$(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@make -C $(RENDU_PATH) fclean
	@rm -f $(NAME)

re: clean fclean all project part1 part2 part2_def bonus bonus_def extra extra_def
