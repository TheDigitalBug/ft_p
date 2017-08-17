/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:57:38 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/24 14:41:01 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_putchat_w_body(wchar_t c, long j)
{
	if (c <= 0x7F)
		j = j + ft_putchar_count(c);
	else if (c <= 0x7FF)
	{
		j = j + ft_putchar_count(0xC0 | (c >> 6));
		j = j + ft_putchar_count(0x80 | (c & 0x3F));
	}
	else if (c <= 0xFFFF)
	{
		j = j + ft_putchar_count(0xE0 | (c >> 12));
		j = j + ft_putchar_count(0x80 | ((c >> 6) & 0x3F));
		j = j + ft_putchar_count(0x80 | (c & 0x3F));
	}
	else if (c <= 0x10FFFF)
	{
		j = j + ft_putchar_count(0xF0 | (c >> 18));
		j = j + ft_putchar_count(0x80 | ((c >> 12) & 0x3F));
		j = j + ft_putchar_count(0x80 | ((c >> 6) & 0x3F));
		j = j + ft_putchar_count(0x80 | (c & 0x3F));
	}
	return (j);
}

long	ft_putchar_w(wchar_t c, t_flag *f)
{
	long	j;

	j = 0;
	while ((f->len - 1 > j) && (f->left != 1))
		if (f->zero == 1)
			j = j + ft_putchar_count('0');
		else
			j = j + ft_putchar_count(' ');
	j = j + ft_putchat_w_body(c, j);
	while ((f->len - j > 0) && (f->left == 1))
		j = j + ft_putchar_count(' ');
	return (j);
}
