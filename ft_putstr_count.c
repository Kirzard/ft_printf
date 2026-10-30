/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadupin <tadupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:33:21 by tadupin           #+#    #+#             */
/*   Updated: 2026/10/29 15:43:04 by tadupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putstr_count(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	write(fd, s, ft_strlen(s));
	count = ft_strlen(s);
	return (count);
}
