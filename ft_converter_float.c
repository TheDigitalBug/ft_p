/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:08:32 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/23 16:02:05 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_print_int(uintmax_t int_part, char *buf, t_flag *f, int minus)
{
	long i;
	long j;

	i = 0;
	j = 0;
	if ((f->space == 1) && (minus == 0) && f->sign != 1)
		j = j + ft_putchar_count(' ');
	if ((minus == 0) && f->sign == 1)
		j = j + ft_putchar_count('+');
	while ((int_part / 10) > 0)
	{
		buf[i] = int_part % 10 + '0';
		i++;
		int_part = int_part / 10;
	}
	buf[i] = int_part % 10 + '0';
	while (i >= 0)
	{
		j = j + ft_putchar_count(buf[i]);
		buf[i] = '\0';
		i--;
	}
	return (j);
}

static long	ft_print_float(double float_part, char *buf, t_flag *f)
{
	long i;
	long j;
	long k;

	i = 0;
	j = 0;
	while (((uintmax_t)float_part / 10) > 0)
	{
		buf[i] = (uintmax_t)float_part % 10 + '0';
		i++;
		float_part = (uintmax_t)float_part / 10;
	}
	buf[i] = (uintmax_t)float_part % 10 + '0';
	k = 0;
	while (i >= 0)
	{
		j = j + ft_putchar_count(buf[i]);
		i--;
		k++;
	}
	while (++k < f->prec)
	{
		j = j + ft_putchar_count('0');
	}
	return (j);
}

long		ft_convert_float(double nb, t_flag *f)
{
	uintmax_t	int_part;
	double		float_part;
	char		buf[65];
	int			minus;
	long		j;

	minus = 0;
	j = 0;
	if (nb < 0)
	{
		minus = -1;
		j = ft_putchar_count('-');
		nb = -nb;
	}
	int_part = (uintmax_t)nb;
	float_part = (nb - (double)int_part);
	j = j + ft_print_int(int_part, buf, f, minus);
	(f->prec == 0) ? (f->prec = 6) : 1;
	if (f->prec > 0)
	{
		j = j + ft_putchar_count('.');
		float_part = float_part * ft_recursive_power(10, f->prec) + 0.5;
		j = j + ft_print_float(float_part, buf, f);
	}
	return (j);
}
