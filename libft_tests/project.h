/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celegran <celegran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 18:58:31 by celegran          #+#    #+#             */
/*   Updated: 2014/12/08 14:15:04 by celegran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include "testframework.h"
# include <libft.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>

char	map_test(char c);
char	mapi_test(unsigned int i, char c);
void	it_test(char *c);
void	iti_test(unsigned int i, char *c);

# ifdef BONUS
void	del_test(void *data, size_t i);
void	lstiter_test(t_list *ppp);
t_list	*lstmap_test(t_list *list);
# endif

#endif
