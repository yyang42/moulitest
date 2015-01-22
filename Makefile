# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyang <yyang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/08 14:30:51 by celegran          #+#    #+#              #
#    Updated: 2015/01/22 23:22:13 by yyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

help:
	@echo "Usage :\n"
	@echo "\tmake libft_part1"
	@echo "\tmake libft_part2    // Includes part1"
	@echo "\tmake libft_bonus    // Includes part2 and part1\n"
	@echo "\tmake get_next_line"
	@echo "\tmake gnl            // Alias for get_next_line\n"
	@echo "\tmake ft_ls\n"
	@echo "\tmake ft_printf\n"

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

ft_printf:
	@make -C ft_printf_tests

update_deps:
	rm -rf testframework/v3/lst
	mkdir -p testframework/v3/lst
	cp ../projects/common/libft/srcs/lst/* testframework/v3/lst
	cp ../projects/common/libft/includes/lst.h testframework/v3/includes/lst.h

test_fw:
	RENDU_PATH=$(shell pwd)/testframework/fake_rendu/libft make -k libft_part2
	RENDU_PATH=$(shell pwd)/testframework/fake_rendu/get_next_line make -k gnl
	RENDU_PATH=$(shell pwd)/testframework/fake_rendu/get_next_line_with_libft make -k gnl
	RENDU_PATH=$(shell pwd)/testframework/fake_rendu/ft_ls make -k ft_ls
	RENDU_PATH=$(shell pwd)/testframework/fake_rendu/ft_printf make -k ft_printf

.PHONY: help libft_part1 libft_part2 libft_bonus get_next_line gnl ft_ls ft_printf
