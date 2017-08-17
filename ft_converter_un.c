/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_un.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:32:39 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/23 11:05:01 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_print(char *rev, long i, t_flag *f)
{
	long j;

	j = 0;
	while ((f->len - i - 1 > j) && (f->left != 1))
	{
		if (f->prec != 0)
			if (f->len > f->prec)
				(f->zero = 0);
		if (f->zero == 1)
			j = j + ft_putchar_count('0');
		else
			j = j + ft_putchar_count(' ');
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

static long	ft_convert_body(uintmax_t nmbr, char *rev)
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
	return (i);
}

long		ft_convert_un(void *nb, t_flag *f, char format)
{
	char		rev[65];
	long		i;
	uintmax_t	nmbr;

	i = 0;
	(format == 'U') ? ft_fsetlong(f) : 1;
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
	i = ft_convert_body(nmbr, rev);
	while ((f->prec - i - 1) > 0)
		rev[++i] = '0';
	return (ft_print(rev, i, f));
}
