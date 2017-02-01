/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:32:39 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/23 13:28:50 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define LEFT f->len != 0 && f->left == 1

static long	ft_print(int m, char *rev, long i, t_flag *f)
{
	long j;

	j = 0;
	if ((m == 0) && (f->sign == 1))
		rev[++i] = '+';
	if ((f->space == 1) && (m == 0) && (f->sign == 0))
		j = j + ft_putchar_count(' ');
	if (((f->sign == 1) && (f->zero == 1)) || ((m == -1) && f->zero == 1))
	{
		(m == -1) ? write(1, "-", 1) : write(1, "+", 1);
		rev[i] = '0';
		((i > f->len) || (LEFT) || (f->prec < f->len)) ? i-- : 1;
		j++;
	}
	while ((f->len - i - 1 > j) && (f->left != 1))
	{
		((f->prec != 0) && (f->len > f->prec)) ? (f->zero = 0) : 1;
		(f->zero == 1) ? (j = j + ft_putchar_count('0')) : 1;
		(f->zero == 0) ? (j = j + ft_putchar_count(' ')) : 1;
	}
	while (i >= 0)
		j = j + ft_putchar_count(rev[i--]);
	while ((f->len - i - 1 > j) && (f->left == 1))
		j = j + ft_putchar_count(' ');
	return (j);
}

static long	ft_convert_body(uintmax_t nmbr, t_flag *f, char *rev, int minus)
{
	long i;

	i = 0;
	while ((nmbr / 10) > 0)
	{
		rev[i] = nmbr % 10 + '0';
		i++;
		nmbr = nmbr / 10;
	}
	rev[i] = nmbr % 10 + '0';
	while ((f->prec - i - 1) > 0)
	{
		i++;
		rev[i] = '0';
	}
	(minus == -1) ? rev[++i] = '-' : 1;
	return (i);
}

static long	ft_nopresicion(t_flag *f)
{
	long i;

	i = 0;
	while (f->len > i)
		i = i + ft_putchar_count(' ');
	return (i);
}

long		ft_convert_dec(void *nb, t_flag *f, char format)
{
	char		rev[65];
	long		i;
	int			minus;
	intmax_t	n;
	uintmax_t	nmbr;

	minus = 0;
	(format == 'D') ? ft_fsetlong(f) : 1;
	n = (int)nb;
	(f->flong == 1) ? n = (long)nb : 1;
	(f->flong == 2) ? n = (intmax_t)nb : 1;
	(f->h == 1) ? n = (short)nb : 1;
	(f->h == 2) ? n = (char)nb : 1;
	(f->z == 1) ? n = (size_t)nb : 1;
	(f->j == 1) ? n = (intmax_t)nb : 1;
	nmbr = n;
	(n < 0) ? (minus = -1) : 1;
	(n < 0) ? (nmbr = -n) : 1;
	if ((f->prec == -1) && (nmbr == 0))
		return (i = ft_nopresicion(f));
	i = ft_convert_body(nmbr, f, rev, minus);
	return (ft_print(minus, rev, i, f));
}
