/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ull_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:30:00 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ull_len(uint64_t ull)
{
	int	i;

	i = 0;
	if (!ull)
		i = 1;
	while (ull != 0)
	{
		ull = ull / 16;
		i++;
	}
	return (i);
}

char	*ull_to_hex(uint64_t ull)
{
	char		*s;
	char		*hex;
	int			i;

	hex = "0123456789abcdef";
	i = ull_len(ull);
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (i-- > 0)
	{
		s[i] = hex[ull % 16];
		ull = ull / 16;
	}
	return (s);
}
