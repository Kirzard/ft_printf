/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_adr_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadupin <tadupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:54:45 by tadupin           #+#    #+#             */
/*   Updated: 2026/10/29 15:42:04 by tadupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_adr_hex(unsigned long long nb, int rec)
{
	char	*base;
	int		count;

	if (!nb)
	{
		count = ft_putstr_count("(nil)", 1);
		return (count);
	}
	count = 0;
	if (!rec)
	{
		write(1, "0x", 2);
		count += 2;
	}
	base = "0123456789abcdef";
	if (nb >= 16)
		count += put_adr_hex(nb / 16, 1);
	count++;
	write(1, &base[nb % 16], 1);
	return (count);
}
