#include "libftprintf.h"

int	check_flag(char c, va_list args)
{
	if (c == 'c')
		write(1, args, 1);
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(args, int)));
	if (c == 'x')
		return (ft_puthexnbr(va_arg(args, int)));
	if (c == 'X')
		return (ft_putCAPhexnbr(va_arg(args, int)));
	if (c == '%')
		return(ft_putchar('%'));
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

int	main(void)
{
	//unsigned int a = -2147483647;
//	unsigned int a = 11;
	printf("1 -> %% es barrabaja\n");
	ft_printf("2 -> %% es barrabaja");
}
