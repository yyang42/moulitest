# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyang <yyang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/18 09:55:13 by yyang             #+#    #+#              #
#    Updated: 2015/01/18 18:46:08 by yyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===============================================================================
# REQUIRED CONFIGS
#===============================================================================

# NAME = 
# RENDU_PATH_KEY = 

#===============================================================================
# DEFAULTS
#===============================================================================
POST_PATTERN = 
CC_DEBUG = -g
CC_FLAGS = -Werror -Wextra -Wall
define FIRST_RULE
	make exec_tests
endef

all:
	$(FIRST_RULE)

#===============================================================================
# INCLUDES
#===============================================================================

include Makefile_cfg.mk

#===============================================================================
# COMMON
#===============================================================================
RENDU_PATH = $(shell grep $(RENDU_PATH_KEY) ../config.ini | cut -d '=' -f 2)

LIBFT_HEADER_PATH = $(shell find $(RENDU_PATH) -name "libft.h")
ifneq ("$(wildcard $(LIBFT_HEADER_PATH))","")
	LIBFT_HEADER_INCLUDE = -I $(shell dirname $(LIBFT_HEADER_PATH))
endif
CC_INCLUDES = -I . -I ../testframework/v3/includes $(LIBFT_HEADER_INCLUDE) -I $(RENDU_PATH) -I$(RENDU_PATH)/libft/includes
CC_SOURCE = ./tests/*.spec.c main.c utils.c $(CC_SOURCE_EXTRA)
pattern ?= spec.c$$
TEST_FILES = ls -1 tests | grep -e "$(pattern)" | grep -e "$(POST_PATTERN)"
ADD_TESTS = $(shell $(TEST_FILES) | sed -E "s/(.*)\.spec\.c/MT_ADD_SUITE\(mt, \1, suite_\1);/g")
PROTOTYPES = $(shell $(TEST_FILES) | sed -E "s/(.*)\.spec\.c/MT_ADD_PROTO\(\1\);/g")
CC_DEFINES = -DPROTOTYPES="$(PROTOTYPES)" -DADD_TESTS="$(ADD_TESTS)" -DRENDU_PATH="\"$(RENDU_PATH)\""
CC_FRAMEWORK_LIB = -L../testframework/v3 -lmt_framework

exec_tests:
ifneq ("$(wildcard $(RENDU_PATH)/Makefile)","")
	make re -k -C $(RENDU_PATH)
else
ifneq ("$(wildcard $(RENDU_PATH)/libft/Makefile)","")
	make re -k -C $(RENDU_PATH)/libft
endif
endif
	make -k -C ../testframework/v3/
	gcc $(CC_FLAGS) $(CC_DEBUG) $(CC_INCLUDES) $(CC_DEFINES) $(CC_SOURCE) $(CC_LIBS) $(CC_FRAMEWORK_LIB) -o $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	make -k -C $(RENDU_PATH) fclean
	make -k -C ../testframework/v3/ fclean
	rm -f $(NAME)

re: clean fclean all project
