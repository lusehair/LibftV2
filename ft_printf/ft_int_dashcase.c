/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_dashcase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:37:10 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/06 16:42:41 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_int_dashlarge(t_printf *o, char *a_argum, int value, int larg)
{
	int i;

	i = 0;
	if (o->with == 'w' && o->dot == 0 && o->dash == '-')
	{
		ft_putstr(a_argum);
		while (i++ < larg)
			ft_putchar(' ');
		return (larg + ft_strlen(a_argum));
	}
	if (o->with == 'w' && o->dot == '.' && o->pres == 0 && value == 0)
	{
		while (i++ <= larg)
			ft_putchar(' ');
		return (larg);
	}
	return (0);
}

int			ft_int_dashcasucase(t_printf *o, char *a_argum, int value, int size)
{
	int		i;
	int		prec;
	int		larg;

	prec = ft_int_prec(o, size, value);
	larg = ft_intlarg(o, size, value);
	i = 0;
	if (o->with == 'w' && o->dot == '.' && o->dash == '-')
	{
		if (value >= 0)
		{
			while (i++ < prec)
				ft_putchar('0');
			ft_putstr(a_argum);
			i = 0;
			while (i++ < larg)
				ft_putchar(' ');
		}
		ft_int_dashcasucase2(value, larg, prec);
		return (prec + larg + ft_strlen(a_argum));
	}
	return (0);
}

int			ft_int_dashcasucase2(int value, int larg, int prec)
{
	int		i;

	i = 0;
	if (value < 0)
	{
		if (value != -2147483648)
			ft_putchar('-');
		while (i++ < prec)
			ft_putchar('0');
		ft_putnbr(value * -1);
		i = 0;
		while (i++ < larg)
			ft_putchar(' ');
	}
	return (0);
}
