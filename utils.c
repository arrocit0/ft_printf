#include "libftprintf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{	
		write (1, str, 1);
		str++;
		i++;
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
		write (1, "-", 1);
		nb *= (-1);
		i = 1;
	}
	if (nb < 10)
	{
		i++;
		nb += '0';
		write (1, &nb, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (i);
}

int	ft_putunbr(int nb)
{
	static int i;

/*	if (nb < 0)
	{
		nb += 4294967296;
		i = 1;
	}
*/
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

int ft_puthexnbr(int nb)
{
	static int i;
	char	*base;

	base = "0123456789abcdef";
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= (-1);
		i = 1;
	}

	if (nb < 16)
	{
		i++;
		nb = base[nb];
		write (1, &nb, 1);
	}
	else
	{
		ft_putnbr(nb / 16);
		ft_putnbr(nb % 16);
	}
	return (i);
}

int ft_putCAPhexnbr(int nb)
{
	static int i;
	char	*base;

	base = "0123456789ABCDEF";
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= (-1);
		i = 1;
	}

	if (nb < 16)
	{
		i++;
		nb = base[nb];
		write (1, &nb, 1);
	}
	else
	{
		ft_putnbr(nb / 16);
		ft_putnbr(nb % 16);
	}
	return (i);
}

