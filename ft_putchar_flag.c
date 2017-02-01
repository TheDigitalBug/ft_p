/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:57:38 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/23 10:24:15 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_putchar_f(char c, t_flag *f)
{
	long	j;

	j = 0;
	while ((f->len - 1 > j) && (f->left != 1))
	{
		if (f->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		j++;
	}
	write(1, &c, 1);
	j++;
	while ((f->len - j > 0) && (f->left == 1))
	{
		write(1, " ", 1);
		j++;
	}
	return (j);
}
