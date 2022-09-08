/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:53 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEST_H
# define LIBTEST_H

# include "./libft.h"

// unit test type
typedef struct s_test {
	int		type;
	int		nb_tests;
	int		nb_success;
	int		nb_errors;
}	t_test;

// testing functions
void	test_init_struct(t_test *test);
void	test_show_start(t_test *test);
void	test_show_result(t_test *test);

// unit testing functions
void	utest(int is_error, char *s, t_test *test);

#endif