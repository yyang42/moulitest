/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 18:58:31 by celegran          #+#    #+#             */
/*   Updated: 2015/02/26 20:48:14 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include <fw.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *s);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isalpha(int i);
int		ft_isalnum(int i);
int		ft_isprint(int i);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strcat(char *s1, char *s2);
void	ft_bzero(void *s, int n);
void	ft_memset(void *s, int c, int n);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strdup(char *s);
void	ft_cat(int fd);
int		ft_puts(const char *s);;

#endif
