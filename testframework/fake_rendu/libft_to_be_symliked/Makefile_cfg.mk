# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyang <yyang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 14:47:06 by yyang             #+#    #+#              #
#    Updated: 2015/01/22 15:03:35 by yyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Required variables: NAME
include Makefile_cfg.mk

all: $(NAME)

$(NAME):
	gcc -I includes -c *.c
	ar rcs $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
