/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsetlong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:57:45 by kkotliar          #+#    #+#             */
/*   Updated: 2017/01/23 13:58:11 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fsetlong(t_flag *f)
{
	f->flong = 1;
	f->h = 0;
	f->z = 0;
	f->j = 0;
}
