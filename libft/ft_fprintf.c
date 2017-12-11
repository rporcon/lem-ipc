/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:54:13 by rporcon           #+#    #+#             */
/*   Updated: 2017/08/19 18:54:21 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	format_fd(char **fmt, va_list ap, int fd)
{
	if (**fmt == 'c')
		ft_putchar_fd((unsigned char)va_arg(ap, int), fd);
	else if (**fmt == 's')
		ft_putstr_fd(va_arg(ap, char*), fd);
	else if (**fmt == 'd')
		ft_putnbr_fd(va_arg(ap, int), fd);
	else if (**fmt == 'u')
		ft_putnbr_u(va_arg(ap, unsigned int));
	else if (ft_strncmp(*fmt, "llu", 3) == 0 && (*fmt += 2))
		ft_putnbr_llu(va_arg(ap, unsigned long long));
	else if (ft_strncmp(*fmt, "zu", 2) == 0 && (*fmt)++)
		ft_putnbr_max_fd(va_arg(ap, size_t), fd);
	else if (**fmt == 'p')
		ft_putaddr_fd(va_arg(ap, void*), fd);
	else if (**fmt == '%')
		ft_putchar_fd('%', fd);
}

void	ft_fprintf(int fd, char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && fmt++)
			format_fd(&fmt, ap, fd);
		else
			ft_putchar_fd(*fmt, fd);
		fmt++;
	}
	va_end(ap);
}
