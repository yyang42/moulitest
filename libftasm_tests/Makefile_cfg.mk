NAME = libfts_tests
RENDU_PATH_KEY = LIBFTASM_PATH
CC_LIBS = -lfts -L $(RENDU_PATH)

override define FIRST_RULE
	@make usage
endef

usage:
	@echo "Usage:"
	@echo "\tmake part1"
	@echo "\tmake part2\t--> Also runs part1"
	@echo "\tmake bonus\t--> Also runs part1 and part2"

part1_init:
	$(eval POST_PATTERN = "00_part1")
part1: part1_init exec_tests

part2_init:
	$(eval POST_PATTERN = "\(00_part1\)\|\(01_part2\)")
part2: part2_init exec_tests

bonus_init:
	$(eval POST_PATTERN = "")
bonus: bonus_init exec_tests
