/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadupin <tadupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:40:11 by tadupin           #+#    #+#             */
/*   Updated: 2026/10/30 13:29:38 by tadupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static int	put_flag(int *flag, int prefixe)
{
	int	i;

	i = 0;
	if (prefixe)
	{
		if(flag[0] == 2)
		{
			while(i < flag[1])
			{
				write(1, "0", 1);
				i++;
			}
		}
	}
	else
	{
		if(flag[0] == 1)
		{
			while(i < flag[1])
			{
				write(1, " ", 1);
				i++;
			}
		}
	}
	return (i);
}
static int	which_arg(va_list	arg, char param, int *flag)
{
	int	count;

	put_flag(flag, 1);
	count = 1;
	if (param == 'c')
		ft_putchar_fd(va_arg(arg, int), 1);
	else if (param == 's')
		count = ft_putstr_count(va_arg(arg, char *), 1);
	else if (param == 'p')
		count = put_adr_hex((unsigned long long)va_arg(arg, void *), 0);
	else if (param == 'd')
		count = ft_putnbr_count(va_arg(arg, int), 1);
	else if (param == 'i')
		count = ft_putnbr_count(va_arg(arg, int), 1);
	else if (param == 'u')
		count = ft_putunsnbr_count(va_arg(arg, unsigned int), 1);
	else if (param == 'x' || param == 'X')
		count = ft_putnbr_hex(va_arg(arg, int), param);
	else if (param == '%')
		ft_putchar_fd('%', 1);
	return (count);
	put_flag(flag, 0);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	size_t		i;
	int			count;
	int			flag[2];

	i = 0;
	flag[0] = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			ft_putchar_fd(format[i], 1);
			i++;
			count++;
		}
		if (!format[i])
			break ;
		i++;
		count += which_flag((char *)&format[i], flag);
		count += which_arg(arg, format[i], flag);
		i++;
	}
	va_end(arg);
	return (i);
}
