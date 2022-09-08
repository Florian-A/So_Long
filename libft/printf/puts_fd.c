/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_fd.c 		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by f██████           #+#    #+#             */
/*   Updated: 2021/11/16 13:43:19 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	puts_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		i += puts_fd("(null)", fd);
		return (i);
	}
	while (s[i])
		i += putc_fd(s[i], fd);
	return (i);
}
