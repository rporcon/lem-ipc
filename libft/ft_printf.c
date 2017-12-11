/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:25:01 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/02 17:22:08 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	format(char **fmt, va_list ap)
{
	if (**fmt == 'c')
		ft_putchar((unsigned char)va_arg(ap, int));
	else if (**fmt == 's')
		ft_putstr(va_arg(ap, char*));
	else if (**fmt == 'd')
		ft_putnbr(va_arg(ap, int));
	else if (**fmt == 'u')
		ft_putnbr_u(va_arg(ap, unsigned int));
	else if (ft_strncmp(*fmt, "llu", 3) == 0 && (*fmt += 2))
		ft_putnbr_llu(va_arg(ap, unsigned long long));
	else if (ft_strncmp(*fmt, "zu", 2) == 0 && (*fmt)++)
		ft_putnbr_max(va_arg(ap, size_t));
	else if (**fmt == 'p')
		ft_putaddr(va_arg(ap, void*));
	else if (**fmt == '%')
		ft_putchar('%');
}

void	ft_printf(char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && fmt++)
			format(&fmt, ap);
		else
			ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
}
