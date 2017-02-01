/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:58:21 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/23 15:07:00 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_puts_count(char const *s, t_flag *f)
{
	long	i;
	long	j;

	j = 0;
	i = 0;
	if (s == NULL)
		(s = "(null)");
	while (s[i] != 0)
		i++;
	if (f->prec > 0)
	{
		(i - f->prec >= 0) ? (i = f->prec) : 1;
	}
	else
		(f->prec == -1) ? (i = 0) : 1;
	while ((f->len - i > j) && (f->left != 1))
		if (f->zero == 1)
			j = j + ft_putchar_count('0');
		else
			j = j + ft_putchar_count(' ');
	write(1, s, i);
	j = j + i;
	while ((f->len - j > 0) && (f->left == 1))
		j = j + ft_putchar_count(' ');
	return (j);
}
