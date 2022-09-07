/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:59:00 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	itoa_len(const int n1)
{
	unsigned int	i;
	unsigned int	n2;

	i = 0;
	if (n1 < 0 || n1 == 0)
	{
		n2 = -(int)n1;
		i++;
	}
	else
		n2 = (int)n1;
	while (n2 / 10 > 0)
	{
		n2 = n2 / 10;
		i++;
	}
	if (n2 > 0 && n2 < 10)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	s1_len;
	unsigned int	n1;
	char			*s1;

	s1_len = itoa_len(n);
	if (n < 0)
		n1 = -n;
	else
		n1 = n;
	s1 = ft_calloc(s1_len + 1, sizeof(char));
	if (!s1)
		return (0);
	while (s1_len > 0)
	{
		if (s1_len == 1 && n < 0)
			s1[s1_len - 1] = '-';
		else
			s1[s1_len - 1] = n1 % 10 + '0';
		n1 = n1 / 10;
		s1_len--;
	}
	return (s1);
}
