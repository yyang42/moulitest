NAME = libmt_framework.a
INCLUDES = -I includes
# SRCS = main.c **/*.c
SRCS = srcs/**/*.c
FLAGS = -Wall -Werror -Wextra -ggdb

# C_DIR = srcs/
# O_DIR = .tmp/objects/

# C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep ".*\.c$$")
# C_DIRS = $(shell find $(C_DIR) -type d -follow -print)

all: clean
	gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

# run: re
# 	# gcc $(NAME) main.c -I includes
# 	./a.out
