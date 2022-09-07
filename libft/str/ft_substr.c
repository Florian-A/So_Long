/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:57:00 by f██████           #+#    #+#             */
/*   Updated: 2021/11/08 22:57:00 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s)
		return (0);
	s1_len = (int)len;
	s2_len = ft_strlen(s);
	if (start > s2_len)
		s1_len = 0;
	if (ft_strlen(s + start) < len)
		s1_len = ft_strlen(s + start);
	s1 = ft_calloc(s1_len + 1, sizeof(char));
	if (!s1)
		return (0);
	if (start > s2_len)
		return (s1);
	ft_strlcpy(s1, &((char *)s)[start], s1_len + 1);
	return (s1);
}
