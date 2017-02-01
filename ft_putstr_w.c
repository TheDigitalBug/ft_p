/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:17:22 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/24 14:56:07 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_count(wchar_t const *s)
{
	long i;
	long k;

	k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] <= 0x7F)
			k++;
		else if (s[i] <= 0x7FF)
			k = k + 2;
		else if (s[i] <= 0xFFFF)
			k = k + 3;
		else if (s[i] <= 0x10FFFF)
			k = k + 4;
		i++;
	}
	return (k);
}

static long	ft_print3byte(long j, wchar_t const *s, long i)
{
	j = j + ft_putchar_count(0xE0 | (s[i] >> 12));
	j = j + ft_putchar_count(0x80 | ((s[i] >> 6) & 0x3F));
	j = j + ft_putchar_count(0x80 | (s[i] & 0x3F));
	return (j);
}

static long	ft_print4byte(long j, wchar_t const *s, long i)
{
	j = j + ft_putchar_count(0xF0 | (s[i] >> 18));
	j = j + ft_putchar_count(0x80 | ((s[i] >> 12) & 0x3F));
	j = j + ft_putchar_count(0x80 | ((s[i] >> 6) & 0x3F));
	j = j + ft_putchar_count(0x80 | (s[i] & 0x3F));
	return (j);
}

static long	ft_printbytes(long j, wchar_t const *s, long k, long i)
{
	long n;

	n = 0;
	while ((s[i] != '\0') && (n < k))
	{
		if ((s[i] <= 0x7F) && (n++ + 1 <= k))
			j = j + ft_putchar_count(s[i]);
		else if ((s[i] <= 0x7FF) && (n + 2 <= k))
		{
			j = j + ft_putchar_count(0xC0 | (s[i] >> 6));
			j = j + ft_putchar_count(0x80 | (s[i] & 0x3F));
			n = n + 2;
		}
		else if ((s[i] <= 0xFFFF) && (n + 3 <= k))
		{
			j = ft_print3byte(j, s, i);
			n = n + 3;
		}
		else if ((s[i] <= 0x10FFFF) && ((n = n + 4) + 4 <= k))
		{
			j = ft_print4byte(j, s, i);
		}
		i++;
	}
	return (j);
}

long		ft_putstr_w(wchar_t const *s, t_flag *f)
{
	long	i;
	long	j;
	long	k;

	j = 0;
	if (s == NULL)
		s = L"(null)";
	k = ft_count(s);
	(f->prec == -1) ? (k = 0) : 1;
	(f->prec > 0) ? (k = f->prec) : 1;
	if ((f->len > k) && (f->left != 1))
		while (f->len - k > j)
		{
			(f->zero != 1) ? ft_putchar_count(' ') : 1;
			(f->zero == 1) ? ft_putchar_count('0') : 1;
			j++;
		}
	i = 0;
	j = ft_printbytes(j, s, k, i);
	while ((f->len - j > 0) && (f->left == 1))
		j = j + ft_putchar_count(' ');
	return (j);
}
