/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:32:39 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/24 14:38:48 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_convert_body(uintmax_t nmbr, t_flag *f, char *rev)
{
	long		i;
	static char b[16] = "0123456789abcdef";

	i = 0;
	while ((nmbr / 16) > 0)
	{
		rev[i] = b[nmbr % 16];
		i++;
		nmbr = nmbr / 16;
	}
	rev[i] = b[nmbr % 16];
	while ((f->prec - i - 1) > 0)
	{
		i++;
		rev[i] = '0';
	}
	return (i);
}

static long	ft_converter_print(long i, char format, t_flag *f, char *rev)
{
	long k;
	long j;

	k = 0;
	j = 0;
	(f->sharp == 1) ? k = 2 : 1;
	while ((f->len - i - 1 - k > 0) && (f->left != 1) && (f->zero == 1))
	{
		((f->prec != 0) && (f->len > f->prec)) ? (f->zero = 0) : 1;
		rev[++i] = '0';
	}
	(f->sharp == 1) ? (rev[++i] = 'x') : 1;
	(f->sharp == 1) ? (rev[++i] = '0') : 1;
	while ((f->len - i - 1 > 0) && (f->left != 1) && (f->zero != 1))
		(rev[++i] = ' ');
	while (i >= 0)
		if (format == 'X')
			j = j + ft_putchar_count(ft_toupper(rev[i--]));
		else
			j = j + ft_putchar_count(rev[i--]);
	while ((f->len - i - 1 > j) && (f->left == 1))
		j = j + ft_putchar_count(' ');
	return (j);
}

static long	ft_printf_sharp(t_flag *f)
{
	long i;

	i = 0;
	while ((f->len - 1 > i) && (f->left != 1))
	{
		if ((f->prec != 0) && (f->len > f->prec))
			(f->zero = 0);
		if (f->zero == 1)
			i = i + ft_putchar_count('0');
		else
			i = i + ft_putchar_count(' ');
	}
	return (i);
}

long		ft_convert_hex(void *nb, char format, t_flag *f)
{
	char		rev[65];
	long		i;
	uintmax_t	nmbr;

	i = 0;
	nmbr = (unsigned int)nb;
	(f->flong == 1) ? nmbr = (unsigned long)nb : 1;
	(f->flong == 2) ? nmbr = (unsigned long long)nb : 1;
	(f->h == 1) ? nmbr = (unsigned short)nb : 1;
	(f->h == 2) ? nmbr = (unsigned char)nb : 1;
	(f->z == 1) ? nmbr = (size_t)nb : 1;
	(f->j == 1) ? nmbr = (uintmax_t)nb : 1;
	if ((f->prec == -1) && (nmbr == 0))
	{
		while (f->len > i)
			i = i + ft_putchar_count(' ');
		return (i);
	}
	if ((f->sharp == 1) && (nmbr == 0))
	{
		i = ft_printf_sharp(f);
		return (i = i + ft_putchar_count('0'));
	}
	i = ft_convert_body(nmbr, f, rev);
	return (ft_converter_print(i, format, f, rev));
}
