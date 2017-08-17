/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:27:09 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/23 13:30:38 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_read_type(const char *format, long i, t_flag *f, va_list *arg)
{
	long ret;

	ret = 0;
	ft_fcheck(f);
	if ((format[i] == 'f') || (format[i] == 'F'))
		ret = ft_convert_float(va_arg(*arg, double), f);
	if ((format[i] == 'd') || (format[i] == 'i') || format[i] == 'D')
		ret = ft_convert_dec(va_arg(*arg, void *), f, format[i]);
	if (format[i] == 'u' || format[i] == 'U')
		ret = ft_convert_un(va_arg(*arg, void *), f, format[i]);
	if (format[i] == 'x' || format[i] == 'X')
		ret = ft_convert_hex(va_arg(*arg, void *), format[i], f);
	if (format[i] == 'o' || format[i] == 'O')
		ret = ft_convert_oct(va_arg(*arg, void *), f, format[i]);
	if (format[i] == 'c')
		(f->flong == 1) ? (ret = ft_putchar_w((wint_t)va_arg(*arg, void *), f))
			: (ret = ft_putchar_f((int)va_arg(*arg, void *), f));
	if (format[i] == 'C')
		ret = ret + ft_putchar_w((wint_t)va_arg(*arg, void *), f);
	if (format[i] == 's')
		(f->flong == 1) ? (ret = ft_putstr_w(va_arg(*arg, wchar_t *), f)) :
		(ret = ft_puts_count(va_arg(*arg, char *), f));
	(format[i] == 'S') ? (ret = ft_putstr_w(va_arg(*arg, wchar_t *), f)) : 1;
	(format[i] == 'p') ? (ret = ft_convert_p(va_arg(*arg, void *), f)) : 1;
	return (ret);
}
