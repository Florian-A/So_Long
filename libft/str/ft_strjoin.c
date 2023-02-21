/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:57:00 by f██████           #+#    #+#             */
/*   Updated: 2023/02/21 01:07:54 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s3_len;
	char	*s3;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1) + 1;
	s3_len = s1_len + ft_strlen(s2);
	s3 = ft_calloc(s3_len, sizeof(char));
	if (!s3)
		return (0);
	ft_strlcat(s3, s1, s1_len);
	ft_strlcat(s3, s2, s3_len);
	return (s3);
}
