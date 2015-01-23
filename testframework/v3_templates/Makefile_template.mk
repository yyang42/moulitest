# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyang <yyang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/18 09:55:13 by yyang             #+#    #+#              #
#    Updated: 2015/01/23 16:16:16 by yyang            ###   ########.fr        #
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
FRAMEWORK_PATH = ../testframework/v3/
RENDU_MAKE_ARG = re
PATTERN ?= spec.c$$
define FIRST_RULE
	make exec_tests
endef

ifeq ("$(RENDU_PATH)", "")
	RENDU_PATH ?= $(shell grep $(RENDU_PATH_KEY) ../config.ini | cut -d '=' -f 2)
endif

all:
	$(FIRST_RULE)

# LIBFT_HEADER_PATH = $(shell find $(RENDU_PATH) -name "libft.h")

# ifneq ("$(wildcard $(LIBFT_HEADER_PATH))","")
# 	LIBFT_HEADER_INCLUDE = -I $(shell dirname $(LIBFT_HEADER_PATH))
# endif

#===============================================================================
# INCLUDES
#===============================================================================

include Makefile_cfg.mk

#===============================================================================
# COMMON
#===============================================================================
TESTS_PATH = tests
CC_INCLUDES = -I . -I $(FRAMEWORK_PATH)/includes $(LIBFT_HEADER_INCLUDE) -I $(RENDU_PATH) -I$(RENDU_PATH)/libft/includes
CC_SOURCE = $(TESTS_PATH)/*.spec.c main.c utils.c $(CC_SOURCE_EXTRA)
TEST_FILES = $(shell find tests -name "*.spec.c" -type f -follow -print)

ADD_TESTS = $(shell echo "$(TEST_FILES)" | sed -E "s/$(TESTS_PATH)\/([^ ]*)\.spec\.c/MT_ADD_SUITE\(mt, \1, suite_\1);/g")
PROTOTYPES = $(shell echo "$(TEST_FILES)" | sed -E "s/$(TESTS_PATH)\/([^ ]*)\.spec\.c/MT_ADD_PROTO\(\1\);/g")
CC_DEFINES = -DPROTOTYPES="$(PROTOTYPES)" -DADD_TESTS="$(ADD_TESTS)" -DRENDU_PATH="\"$(RENDU_PATH)\""
CC_FRAMEWORK_LIB = -L$(FRAMEWORK_PATH) -lmt_framework

exec_tests:
ifneq ("$(wildcard $(RENDU_PATH)/Makefile)","")
	make $(RENDU_MAKE_ARG) -k -C $(RENDU_PATH)
else
ifneq ("$(wildcard $(RENDU_PATH)/libft/Makefile)","")
	make $(RENDU_MAKE_ARG) -k -C $(RENDU_PATH)/libft
endif
endif
	make -k -C $(FRAMEWORK_PATH)
	gcc $(CC_FLAGS) $(CC_DEBUG) $(CC_INCLUDES) $(CC_DEFINES) $(CC_SOURCE) -o $(NAME) $(CC_FRAMEWORK_LIB) $(CC_LIBS)
	./$(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	make -k -C $(RENDU_PATH) fclean
	make -k -C $(FRAMEWORK_PATH) fclean
	rm -f $(NAME)

re: clean fclean all project
