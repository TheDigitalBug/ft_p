/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:32:39 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/23 19:13:54 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_print(char *rev, long i, t_flag *f)
{
	long j;

	j = 0;
	while ((f->len - i - 1 > j) && (f->left != 1))
	{
		if ((f->prec != 0) && (f->len > f->prec))
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

long		ft_convert_p(void *nb, t_flag *f)
{
	char		rev[65];
	long		i;
	long		j;
	uintptr_t	nmbr;
	static char	b[16] = "0123456789abcdef";

	i = 0;
	nmbr = (uintptr_t)nb;
	while ((nmbr / 16) > 0)
	{
		rev[i] = b[nmbr % 16];
		i++;
		nmbr = nmbr / 16;
	}
	rev[i] = b[nmbr % 16];
	((f->prec == -1) && (nmbr == 0)) ? i = -1 : 1;
	while (((f->prec - i - 1) > 0) || (nmbr == 0 &&
				(f->len - 3 > i) && (f->zero == 1)))
		rev[++i] = '0';
	rev[++i] = 'x';
	rev[++i] = '0';
	return (j = ft_print(rev, i, f));
}
