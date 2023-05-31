#ifndef LIBPRINTF_H
#define LIBPRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putunbr(int nb);
int		ft_puthexnbr(int nb);
int 	ft_putCAPhexnbr(int nb);

#endif