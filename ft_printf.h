/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadupin <tadupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:43:26 by tadupin           #+#    #+#             */
/*   Updated: 2026/10/30 12:55:18 by tadupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr_count(int n, int fd);
int		ft_putunsnbr_count(unsigned int n, int fd);
int		ft_putstr_count(char *s, int fd);
int		ft_putnbr_hex(unsigned int n, int format);
int		put_adr_hex(unsigned long long nb, int rec);
int		which_flag(char *param, int *flag);

#endif