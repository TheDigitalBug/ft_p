/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:21:38 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/23 11:29:59 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_read_fs(const char *format, long i, t_flag *f)
{
	if ((format[i] == '0') && ((format[i - 1] < '1' || format[i - 1] > '9')))
	{
		f->zero = 1;
		return (++i);
	}
	if ((format[i] == ' ') || (format[i] == '-') || (format[i] == '+') ||
			(format[i] == '#'))
	{
		(format[i] == ' ') ? f->space = 1 : 0;
		(format[i] == '-') ? f->left = 1 : 0;
		(format[i] == '+') ? f->sign = 1 : 0;
		(format[i] == '#') ? f->sharp = 1 : 0;
		i++;
		return (i);
	}
	if (format[i] >= '1' && format[i] <= '9')
	{
		f->len = ft_atoi(format + i);
		while ((format[i] >= '0') && (format[i] <= '9'))
			i++;
		return (i);
	}
	return (0);
}

long	ft_read_precision(const char *format, long i, t_flag *f)
{
	if (format[i] == '.')
	{
		i++;
		f->prec = ft_atoi(format + i);
		while ((format[i] >= '0') && (format[i] <= '9'))
			i++;
		if (f->prec == 0)
			f->prec = -1;
		return (i);
	}
	return (0);
}

long	ft_read_field_widht(const char *format, long i, t_flag *f,
		va_list *arg)
{
	if ((format[i] == '*') && (format[i - 1] != '.'))
	{
		i++;
		f->len = va_arg(*arg, int);
		if (f->len < 0)
		{
			f->len = -f->len;
			f->left = 1;
		}
		return (i);
	}
	if ((format[i] == '*') && (format[i - 1] == '.'))
	{
		i++;
		f->prec = va_arg(*arg, int);
		if (f->prec < 0)
			f->prec = 0;
		else if (f->prec == 0)
			f->prec = -1;
		return (i);
	}
	return (0);
}

long	ft_read_length(const char *format, long i, t_flag *f)
{
	if (format[i] == 'l')
	{
		f->flong++;
		i++;
		return (i);
	}
	if (format[i] == 'h')
	{
		f->h++;
		i++;
		return (i);
	}
	if (format[i] == 'z')
	{
		f->z = 1;
		i++;
		return (i);
	}
	if (format[i] == 'j')
	{
		f->j = 1;
		i++;
		return (i);
	}
	return (0);
}

long	ft_read_format(const char *format, long *i, t_flag *f, va_list *arg)
{
	long tmp_i;

	if ((tmp_i = ft_read_fs(format, *i, f)) != 0)
		return (*i = tmp_i);
	if ((tmp_i = ft_read_precision(format, *i, f)) != 0)
		return (*i = tmp_i);
	if ((tmp_i = ft_read_field_widht(format, *i, f, arg)) != 0)
		return (*i = tmp_i);
	if ((tmp_i = ft_read_length(format, *i, f)) != 0)
		return (*i = tmp_i);
	f->nonprint = -1;
	return (-1);
}
