/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:32:39 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/23 13:40:39 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_print(char *rev, long i, t_flag *f)
{
	long j;

	j = 0;
	((f->sharp == 1) && (f->prec == 0)) ? j++ : 1;
	while ((f->len - i - 1 > j) && (f->left != 1))
	{
		((f->prec != 0) && (f->len > f->prec)) ? f->zero = 0 : 1;
		(f->zero == 1) ? (j = j + ft_putchar_count('0')) : 1;
		(f->zero != 1) ? (j = j + ft_putchar_count(' ')) : 1;
	}
	if ((f->sharp == 1) && ((f->prec == 0) || (f->prec == -1)))
	{
		write(1, "0", 1);
		(f->prec == -1) ? j++ : j;
	}
	while (i >= 0)
	{
		j = j + ft_putchar_count(rev[i]);
		i--;
	}
	while ((f->len - i - 1 > j) && (f->left == 1))
		j = j + ft_putchar_count(' ');
	return (j);
}

static long	ft_convert_body(uintmax_t nmbr, t_flag *f, char *rev)
{
	long i;

	i = 0;
	while ((nmbr / 8) > 0)
	{
		rev[i] = nmbr % 8 + '0';
		i++;
		nmbr = nmbr / 8;
	}
	rev[i] = nmbr % 8 + '0';
	while ((f->prec - i - 1) > 0)
	{
		i++;
		rev[i] = '0';
	}
	return (i);
}

long		ft_convert_oct(void *nb, t_flag *f, char format)
{
	char		rev[65];
	long		i;
	uintmax_t	nmbr;

	i = 0;
	(format == 'O') ? ft_fsetlong(f) : 1;
	nmbr = (unsigned int)nb;
	(f->flong == 1) ? nmbr = (unsigned long)nb : 1;
	(f->flong == 2) ? nmbr = (unsigned long long)nb : 1;
	(f->h == 1) ? nmbr = (unsigned short)nb : 1;
	(f->h == 2) ? nmbr = (unsigned char)nb : 1;
	(f->z == 1) ? nmbr = (size_t)nb : 1;
	(f->j == 1) ? nmbr = (uintmax_t)nb : 1;
	if ((f->prec == -1) && f->sharp != 1 && (nmbr == 0) && (f->len == 0))
		return (0);
	if ((f->prec == -1) && (f->len != 0))
	{
		while (f->len > i)
			i = i + ft_putchar_count(' ');
		return (i);
	}
	i = ft_convert_body(nmbr, f, rev);
	if ((f->sharp == 1) && (nmbr == 0))
		return (write(1, "0", 1));
	return (ft_print(rev, i, f));
}
