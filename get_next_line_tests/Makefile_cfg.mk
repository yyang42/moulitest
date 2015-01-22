NAME = get_next_line_tests
RENDU_PATH_KEY = GET_NEXT_LINE_PATH

ifneq ("$(wildcard $(RENDU_PATH)/libft)","")
	CC_LIBS = -lft -L $(RENDU_PATH)/libft
endif

CC_SOURCE_EXTRA = $(RENDU_PATH)/get_next_line.c
