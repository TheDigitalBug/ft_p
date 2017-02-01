/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:58:51 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/23 16:06:24 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <locale.h>

typedef	struct	s_flag
{
	int left;
	int space;
	int sign;
	int zero;
	int prec;
	int len;
	int flong;
	int h;
	int z;
	int j;
	int sharp;
	int	nonprint;
}				t_flag;
int				ft_printf(const char *format, ...);
long			ft_convert_dec(void *nb, t_flag *f, char format);
long			ft_convert_un(void *nb, t_flag *f, char format);
long			ft_convert_oct(void *nb, t_flag *f, char format);
long			ft_convert_hex(void *nb, char format, t_flag *f);
long			ft_convert_p(void *nb, t_flag *f);
long			ft_convert_float(double nb, t_flag *f);
long			ft_putchar_count(char c);
long			ft_putchar_f(char c, t_flag *f);
long			ft_putchar_w(wchar_t c, t_flag *f);
long			ft_puts_count(char const *s, t_flag *f);
long			ft_putstr_w(wchar_t const *s, t_flag *f);
long			ft_read_format(const char *format, long *i, t_flag *f,
		va_list *arg);
long			ft_read_fs(const char *format, long i, t_flag *f);
long			ft_read_precision(const char *format, long i, t_flag *f);
long			ft_read_field_widht(const char *format, long i, t_flag *f,
		va_list *arg);
long			ft_read_length(const char *format, long i, t_flag *f);
long			ft_read_type(const char *format, long i, t_flag *f,
		va_list *arg);
void			ft_fbezero(t_flag *f);
void			ft_fcheck(t_flag *f);
void			ft_fsetlong(t_flag *f);
int				ft_recursive_power(int nb, int power);
int				ft_toupper(int c);
int				ft_atoi(const char *str);
char			*ft_strrchr(const char *s, int c);

#endif
