/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign_dashcase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:42:55 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/06 15:43:49 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsign_dashlarge(t_printf *o, char *a_arg, unsigned int val, int lar)
{
	int i;

	i = 0;
	if (o->with == 'w' && o->zero == 0 && o->dot == 0 && o->dash == '-')
	{
		ft_putstr(a_arg);
		while (i++ < lar)
			ft_putchar(' ');
		o->res += lar + ft_strlen(a_arg);
		return (-2);
	}
	if (o->with == 'w' && o->zero == 0 && o->dot == '.' && o->pres == 0
			&& val == 0)
	{
		while (i++ <= lar)
			ft_putchar(' ');
		o->res += lar;
	}
	return (0);
}

int		ft_unsign_dashcasucase(t_printf *o, char *a_argum, int larg, int prec)
{
	int i;

	i = 0;
	if (o->with == 'w' && o->zero == 0 && o->dot == '.' && o->dash == '-')
	{
		while (i++ < prec)
			ft_putchar('0');
		ft_putstr(a_argum);
		i = 0;
		while (i++ < larg)
			ft_putchar(' ');
		return (prec + larg + ft_strlen(a_argum));
	}
	return (0);
}
