# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyang <yyang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/18 09:55:13 by yyang             #+#    #+#              #
#*   Updated: 2016/01/19 00:16:54 by mtassett         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #
                                                       #
# **************************************************************************** #

#===============================================================================
# REQUIRED CONFIGS
#===============================================================================

# NAME =
# RENDU_PATH_KEY =

#===============================================================================
# DEFAULTS
#===============================================================================
POST_PATTERN = ""
CC_FLAGS = -g

FRAMEWORK_PATH = ../testframework/v3/
RENDU_MAKE_ARG = re
CONFIG_INI_PATH = ../config.ini
PATTERN ?= spec.c$$
define FIRST_RULE
	make exec_tests
endef

ifeq ("$(RENDU_PATH)", "")
RENDU_PATH ?= $(shell grep $(RENDU_PATH_KEY) $(CONFIG_INI_PATH) | cut -d '=' -f 2 | sed -E "s/^[ \"]*//" | sed -E "s/[ \"]*$$//")
endif

all:
	$(FIRST_RULE)

#===============================================================================
# INCLUDES
#===============================================================================

include Makefile_cfg.mk

#===============================================================================
# COMMON
#===============================================================================
TESTS_PATH = tests
CC_LIBFT_LIB_DEFAULT = -L $(LIBFT_PATH) -lft
CC_FRAMEWORK_LIB = -L$(FRAMEWORK_PATH) -lmt_framework
CC_INCLUDES = -I . -I $(FRAMEWORK_PATH)/includes -I $(RENDU_PATH) -I $(RENDU_PATH)/includes -I $(RENDU_PATH)/includes/builtin -I $(RENDU_PATH)/libs/libtowel/includes -I $(RENDU_PATH)/libft/includes -I $(RENDU_PATH)/srcs/libft/includes
TEST_FILES = $(shell find tests -name "*.spec.c" -type f -follow -print | grep $(PATTERN))
CC_SOURCE = $(TEST_FILES) main.c utils.c $(CC_SOURCE_EXTRA)
LIBFT_PATH = $(RENDU_PATH)/libft
ADD_TESTS = $(shell echo "$(TEST_FILES)" | perl -pe "s/.*?\/([^\/ ]*)\.spec\.c/MT_ADD_SUITE\(mt, \1, suite_\1); /g")
PROTOTYPES = $(shell echo "$(TEST_FILES)" | perl -pe "s/.*?\/([^\/ ]*)\.spec\.c/MT_ADD_PROTO\(\1\); /g")
CC_DEFINES = -D__MOULITEST__ -DPROTOTYPES="$(PROTOTYPES)" -DADD_TESTS="$(ADD_TESTS)" -DRENDU_PATH="\"$(RENDU_PATH)\""


C_DIR = $(RENDU_PATH)/srcs
O_DIR = .tmp/objects

CC_HEADERS = $(CC_INCLUDES)

C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep ".*\.c$$" | grep -v "\.spec\.c")
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)

H_FILES = $(shell find $(RENDU_PATH)/includes -type f -follow -print | grep ".*\.h$$")
O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)
CC_OPTIONS = -D__MOULITEST__ -g $(CC_HEADERS) $(CC_FLAGS_EXTRA)

$(O_DIR)%.o: $(C_DIR)%.c $(H_FILES)
	@mkdir -p $(O_DIRS) $(O_DIR)
	@gcc $(CC_OPTIONS) $(CONFIG_EXTRA_H) $(LIB_TOWEL_INCLUDES) -o $@ -c $< \
		&& printf "."

exec_tests: $(O_FILES)
	echo "$(TEST_FILES)"
ifneq ("$(wildcard $(RENDU_PATH)/libft/Makefile)","")
	make $(RENDU_MAKE_ARG) -k -C $(LIBFT_PATH)
	$(eval CC_LIBFT_LIB = $(CC_LIBFT_LIB_DEFAULT))
endif
ifneq ("$(wildcard $(RENDU_PATH)/Makefile)","")
	make $(RENDU_MAKE_ARG) -k -C $(RENDU_PATH) $(CC_LIBFT_LIB)
endif
	make -k -C $(FRAMEWORK_PATH)
	$(CC) $(CC_FLAGS) $(CC_INCLUDES) $(CC_DEFINES) $(CC_SOURCE) $^ -o $(NAME) $(CC_FRAMEWORK_LIB) $(CC_LIBS)
	$(shell pwd)/$(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	make -k -C $(RENDU_PATH) fclean
	make -k -C $(FRAMEWORK_PATH) fclean
	rm -f $(NAME)

re: clean fclean all project
