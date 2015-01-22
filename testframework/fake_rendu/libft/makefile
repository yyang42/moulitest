# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 21:37:17 by juschaef          #+#    #+#              #
#    Updated: 2014/11/06 21:37:20 by juschaef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_{atoi,isdigit,memchr,putchar,putstr,strcpy,strjoin,strncmp}.c
SRC += ft_{strsplit,bzero,isprint,memcmp,putchar_fd,putstr_fd,strdel,strlcat}.c
SRC += ft_{strncpy,strstr,isalnum,isspace,memcpy,putendl,strcat,strdup}.c
SRC += ft_{strlen,strnequ,strsub,isalpha,itoa,memdel,putendl_fd,strchr}.c
SRC += ft_{strequ,strmap,strnew,strtrim,isascii,memalloc,memmove,putnbr}.c
SRC += ft_{strclr,striter,strmapi,strnstr,tolower,isblank,memccpy,memset}.c
SRC += ft_{putnbr_fd,strcmp,striteri,strncat,strrchr,toupper,putnendl}.c
SRC += ft_{lstnew,lstdelone,lstdel,lstadd,lstiter,lstmap,replace_char}.c
SRC += ft_{putnstr,memswap,swap,sqrt,factorial,power,sort_int_table}.c
SRC += ft_{islower,isupper,ispunct,abs,rotone,str_capitalize,nrot}.c
SRC += ft_{printable_rotone,strupcase,strlowcase,strrev,realloc,sort_array}.c
SRC += ft_sort_inverted.c get_next_line.c
OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rcs $(NAME) $(OBJECT)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all
