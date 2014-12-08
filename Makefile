# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celegran <celegran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/08 14:30:51 by celegran          #+#    #+#              #
#    Updated: 2014/12/08 14:37:26 by celegran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

help:
	@echo "Usage :\n"
	@echo "\tmake libft_part1"
	@echo "\tmake libft_part2    // Includes part1"
	@echo "\tmake libft_bonus    // Includes part2 and part1\n"
	@echo "\tmake get_next_line"
	@echo "\tmake gnl            // Alias for get_next_line\n"
	@echo "\tmake ft_ls"

libft_part1:
	@make -C libft_tests part1

libft_part2:
	@make -C libft_tests part2

libft_bonus:
	@make -C libft_tests bonus

get_next_line:
	@make -C get_next_line_tests

gnl: get_next_line

ft_ls:
	@make -C ft_ls_tests

.PHONY: help libft_part1 libft_part2 libft_bonus get_next_line gnl ft_ls
