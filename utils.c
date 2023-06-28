/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocimart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:44:15 by rocimart          #+#    #+#             */
/*   Updated: 2023/06/28 05:32:47 by rocimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);	
	}
	while (str[i] != '\0')
	{
		i += ft_putchar(str[i]);
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	static int i;

	if (nb == -2147483648)
	{
		write (1, "-2", 2);
		nb = 147483648;
		i = 2;
	}	
	if (nb < 0)
	{
		i = ft_putchar('-');
		nb *= (-1);
	}
	if (nb <= 9)
	{
		nb += '0';
		i += ft_putchar(nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (i);
}

int	ft_putunbr(int n)
{
	static int		i;
	unsigned int	nb;

	nb = (unsigned int)n;
	if (nb < 10)
	{
		i++;
		nb += '0';
		write (1, &nb, 1);
	}
	else
	{
		ft_putunbr(nb / 10);
		ft_putunbr(nb % 10);
	}
	return (i);
}

int ft_puthexnbr(unsigned int nbr)
{
	static int 		i;
	char			*base;
	unsigned int	nb;

	nb = (unsigned int)nbr;
	base = "0123456789abcdef";
	if (nb < 16)
		i += ft_putchar(base[nb]);
	else
	{
		ft_puthexnbr(nb / 16);
		ft_puthexnbr(nb % 16);
	}
	return (i);
}

int ft_putCAPhexnbr(int nbr)
{
	static int i;
	char	*base;
	unsigned int	nb;

	nb = (unsigned int)nbr;
	base = "0123456789ABCDEF";
	if (nb < 0)
	{
		i = ft_putchar('-');
		nb *= (-1);
	}
	if (nb < 16)
		i += ft_putchar(base[nb]);
	else
	{
		ft_putCAPhexnbr(nb / 16);
		ft_putCAPhexnbr(nb % 16);
	}
	return (i);
}

int	ft_putptr(void *pt)
{
	int len;
	int ptr;

	ptr = (unsigned long long)pt;
	len = ft_putstr("0x");
	len += ft_puthexnbr(ptr);
	return(len);
}
