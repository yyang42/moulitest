/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 00:54:40 by celegran          #+#    #+#             */
/*   Updated: 2015/01/26 16:20:19 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Project headers
*/

#ifndef PROJECT_H
# define PROJECT_H

# include <fw.h>

void mt_assert_sh_stdout(t_test *test, char *commands, char *stdout_filter);
void mt_assert_sh_stderr_not_empty(t_test *test, char *commands);
void mt_assert_sh_stderr_is_empty(t_test *test, char *commands);
void mt_assert_sh_stdout_not_contains(t_test *test, char *commands, char *filter);

#endif
