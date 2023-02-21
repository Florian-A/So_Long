/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by f██████           #+#    #+#             */
/*   Updated: 2023/02/21 01:07:54 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_atol(const char *str)
{
	int			i;
	long long	n;
	int			s;

	i = 0;
	n = 0;
	s = 1;
	while (((str[i] >= '\011') && (str[i] <= '\015')) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			s = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((n * 10 + (str[i] - '0')) / 10 != n && s == -1)
			return (0);
		else if ((n * 10 + (str[i] - '0')) / 10 != n)
			return (0);
		n = n * 10 + str[i] - '0';
		i++;
	}
	return ((long)(n * s));
}
