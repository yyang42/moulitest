# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyang <yyang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 14:47:06 by yyang             #+#    #+#              #
#    Updated: 2015/01/23 21:33:28 by yyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Required variables: NAME
include Makefile_cfg.mk

FLAGS = -I includes -I .

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c *.c
ifeq ($(OUTPUT_TYPE), lib)
	ar rcs $(NAME) *.o
endif
ifeq ($(OUTPUT_TYPE), exec)
	@gcc $(FLAGS) *.o -o $@
endif
	@echo "$(COL_GREEN)$(NAME)$(COL_RESET)"

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
