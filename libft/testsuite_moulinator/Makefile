# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyang <yyang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/29 17:36:12 by mvaude            #+#    #+#              #
#    Updated: 2014/11/10 15:43:53 by yyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Moulinette
RENDU_PATH = ./../../../libft

all: $(NAME)

$(NAME):
	@gcc -fPIC -Wall -Werror -Wextra -c $(RENDU_PATH)/*.c
	@gcc -fPIC -Werror -Wall -Wextra -shared -o libft.so *.o
	./Mouli-nator

clean:
	@rm -rf *.o
	@rm -rf libft.so

re: clean all
