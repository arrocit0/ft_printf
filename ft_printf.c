/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocimart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:44:26 by rocimart          #+#    #+#             */
/*   Updated: 2023/06/28 05:32:46 by rocimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(char c, va_list args)
{
	if (c == 'c')
		return(ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(args, int)));
	if (c == 'x')
		return (ft_puthexnbr(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_putCAPhexnbr(va_arg(args, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	return(1);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += check_flag((str[i]), args);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

