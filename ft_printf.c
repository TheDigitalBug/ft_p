/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:44:38 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/24 15:32:50 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_return(long ret, t_flag *f)
{
	free(f);
	return (ret);
}

static int	ft_printf_body(const char *format, long ret, t_flag *f,
		va_list *arg)
{
	long	i;

	i = 0;
	ret = 0;
	while (format[i])
	{
		ft_fbezero(f);
		while ((format[i] != '%') && (format[i] != '\0'))
			ret = ret + ft_putchar_f(format[i++], f);
		if ((format[i] == '\0') || (format[i] == '%' && format[i + 1] == '\0'))
			return ((int)ret);
		i++;
		while (ft_strrchr("dDisScCxXoOfFuUp\0", format[i]) == NULL)
			if (ft_read_format(format, &i, f, arg) == -1)
				break ;
		if (format[i] == '\0')
			return ((int)ret);
		(f->nonprint != -1) ? (ret = ret + ft_read_type(format, i, f, arg)) :
		(ret = ret + ft_putchar_f(format[i], f));
		i++;
	}
	return ((int)ret);
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	long	ret;
	t_flag	*f;

	ret = 0;
	va_start(arg, format);
	if ((f = (t_flag*)malloc(sizeof(*f))) == NULL)
		return (0);
	ret = ft_printf_body(format, ret, f, &arg);
	va_end(arg);
	return ((int)ft_return(ret, f));
}
