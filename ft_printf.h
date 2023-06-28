/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocimart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:44:40 by rocimart          #+#    #+#             */
/*   Updated: 2023/06/28 05:32:41 by rocimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
#define LIBPRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putunbr(int nb);
int		ft_puthexnbr(unsigned int nbr);
int 	ft_putCAPhexnbr(int nbr);
int		ft_putptr(void *ptr);
int		check_flag(char c, va_list args);
int		ft_printf(const char *str, ...);
#endif
