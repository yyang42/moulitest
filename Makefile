# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyang <yyang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/08 14:30:51 by celegran          #+#    #+#              #
#    Updated: 2015/02/14 21:47:00 by yyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Allow the usage of platform-specific tools through environment variables.
MAKE ?= make
CC ?= gcc


help:
	@echo "Usage :"
	@echo "\tmake libft_part1"
	@echo "\tmake libft_part2    // Includes part1"
	@echo "\tmake libft_bonus    // Includes part2 and part1"
	@echo "\tmake get_next_line or gnl"
	@echo "\tmake ft_ls"
	@echo "\tmake ft_printf"
	@echo ""

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

check:
	MAKEFLAGS="" RENDU_PATH=$(shell pwd)/testframework/fake_rendu/libft make -k libft_bonus
	MAKEFLAGS="" RENDU_PATH=$(shell pwd)/testframework/fake_rendu/libft_part1 make -k libft_part1
	MAKEFLAGS="" RENDU_PATH=$(shell pwd)/testframework/fake_rendu/libft_part2 make -k libft_part2
	MAKEFLAGS="" RENDU_PATH=$(shell pwd)/testframework/fake_rendu/libft make -k libft_part2
	MAKEFLAGS="" RENDU_PATH=$(shell pwd)/testframework/fake_rendu/get_next_line make -k gnl
	MAKEFLAGS="" RENDU_PATH=$(shell pwd)/testframework/fake_rendu/get_next_line_with_libft make -k gnl

	# Does not work on the continuous integration for a misterious reason ...
	# MAKEFLAGS="" RENDU_PATH=$(shell pwd)/testframework/fake_rendu/ft_ls make -k ft_ls

	MAKEFLAGS="" RENDU_PATH=$(shell pwd)/testframework/fake_rendu/ft_printf make -k ft_printf
	MAKEFLAGS="" RENDU_PATH=$(shell pwd)/testframework/fake_rendu/ft_printf_with_libft make -k ft_printf
	MAKEFLAGS="" RENDU_PATH=$(shell pwd)/testframework/fake_rendu/ft_printf make -k ft_printf PATTERN=01

.PHONY: help libft_part1 libft_part2 libft_bonus get_next_line gnl ft_ls ft_printf
