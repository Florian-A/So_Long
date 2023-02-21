/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:04:58 by f██████           #+#    #+#             */
/*   Updated: 2023/02/21 01:07:54 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtest.h"

void	test_init_struct(t_test *test)
{
	test->nb_tests = 0;
	test->nb_success = 0;
	test->nb_errors = 0;
}
