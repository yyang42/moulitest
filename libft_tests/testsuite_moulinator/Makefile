# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/29 17:36:12 by mvaude            #+#    #+#              #
#    Updated: 2014/11/10 17:59:02 by juschaef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Moulinette
RENDU_PATH = $(shell awk -F "=" '/LIBFT_PATH/ {print $$2}' ../../config)

all: $(NAME)

$(NAME):
	@gcc -fPIC -Wall -Werror -Wextra -c $(RENDU_PATH)/*.c
	@gcc -fPIC -Werror -Wall -Wextra -shared -o libft.so *.o
	./Mouli-nator

clean:
	@rm -rf *.o
	@rm -rf libft.so

re: clean all
