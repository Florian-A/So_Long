/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:03:24 by f██████           #+#    #+#             */
/*   Updated: 2023/02/21 01:07:54 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	put_va(int fd, va_list args, const char *fmt, int *i)
{
	while (*fmt)
	{
		if (fmt[0] == '%' && fmt[1] != '\0' && ft_strchr("scdiupxX%", fmt[1]))
		{
			if (fmt[1] == 's')
				*i += puts_fd(va_arg(args, char *), fd);
			else if (fmt[1] == 'c')
				*i += putc_fd(va_arg(args, int), fd);
			else if (fmt[1] == 'd' || fmt[1] == 'i')
				*i += putdi_fd(va_arg(args, int), fd);
			else if (fmt[1] == 'u')
				*i += putu_fd(va_arg(args, int), fd);
			else if (fmt[1] == 'p')
				*i += putp_fd(va_arg(args, unsigned long long), fd) + 1;
			else if (fmt[1] == 'x')
				*i += putx1_fd(va_arg(args, unsigned long long), fd);
			else if (fmt[1] == 'X')
				*i += putx2_fd(va_arg(args, unsigned long long), fd);
			else if (fmt[1] == '%')
				*i += putc_fd(fmt[1], fd);
			fmt = fmt + 2;
		}
		else
			*i += putc_fd(fmt++[0], 1);
	}
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, fmt);
	put_va(1, args, fmt, &i);
	va_end(args);
	return (i);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, fmt);
	put_va(fd, args, fmt, &i);
	va_end(args);
	return (i);
}
