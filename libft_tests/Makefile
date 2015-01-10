NAME = libft_test
FLAGS = -Werror -Wall -Wextra
SOURCE = ../testframework/v2/*.c main.c ./part1/*.c utils.c
tests ?= spec.c$$
RENDU_PATH = $(shell grep LIBFT_PATH ../config.ini | cut -d '=' -f 2)
PROTOTYPES = $(shell ls -1 part1 part2 bonus extra | grep -v ':' | sed -E "s/(.*)\.spec\.c/UT_TEST\(\1\);/g")
DEFINES = -DPROTOTYPES="$(PROTOTYPES)" -DRENDU_PATH="\"$(RENDU_PATH)\""
INCLUDES = -I $(RENDU_PATH) -I $(RENDU_PATH)/includes -I ../testframework/v2 -I.
PARTS_DIRS = part1

# @echo "\tmake extra\t--> Also runs part1, part2 and bonus (You need to set extra tests in config.ini)"
# @echo "\nCorrection:\n\tmake check_forbidden_fn\n"

all:
	@echo "Usage:\n\tmake part1\n\tmake part2\t--> Also runs part1"
	@echo "\tmake bonus\t--> Also runs part1 and part2"

part2_def:
	$(eval PARTS_DIRS += part2)
	$(eval SOURCE += ./part2/*.c)

part2: part2_def part1

bonus_def: part2_def
	$(eval PARTS = -DBONUS)
	$(eval PARTS_DIRS += bonus)
	$(eval SOURCE += ./bonus/*.c)

bonus: bonus_def part1

extra_def: bonus_def
	$(eval PARTS_DIRS += extra)
	$(eval SOURCE += ./extra/*.c)

extra: extra_def part1

project:
	@make -C $(RENDU_PATH)

part1: fclean project
	$(eval ADD_TESTS = $(shell ls -1 $(PARTS_DIRS) | grep -v ':' | grep -e "$(tests)" | sed -E 's/(.*)\.spec\.c/ut_add_test\(\&ut_test_\1, \\\"\1\\\"\);/'))
	$(eval DEFINES += -DADD_TESTS="$(ADD_TESTS)")
	@gcc -g $(FLAGS) $(INCLUDES) $(DEFINES) $(PARTS) -L$(RENDU_PATH) $(SOURCE) -o $(NAME) -lft
	@./$(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@make -C $(RENDU_PATH) fclean
	@rm -f $(NAME)

re: fclean part1

.PHONY: clean fclean all project part1 part2 part2_def bonus bonus_def extra extra_def
