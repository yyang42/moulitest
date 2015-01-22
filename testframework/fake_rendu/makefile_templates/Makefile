# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyang <yyang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 14:47:06 by yyang             #+#    #+#              #
#    Updated: 2015/01/22 15:09:08 by yyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -I includes -I . -c *.c
	ar rcs $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
