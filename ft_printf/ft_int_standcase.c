/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_standcase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:43:04 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/12 16:18:23 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_intlargecase(t_printf *o, char *a_argum, int value, int larg)
{
	int		i;

	if (o->zero == '0' && o->dot == '.' && o->pres == 0)
		o->zero = 0;
	i = 0;
	if (o->nb == 0 && o->dot == '.' && o->pres == 0 && value == 0
			&& o->dash == 0)
	{
		o->res += 0;
		free(a_argum);
		return (-2);
	}
	if (o->dot == '.' && o->nb != 0 && o->pres == 0 && value == 0)
	{
		while (i++ <= larg)
			ft_putchar(' ');
		o->res += o->nb;
		return (-2);
	}
	ft_intlargecase2(o, a_argum, value, larg);
	return (0);
}

int			ft_intlargecase2(t_printf *o, char *a_argum, int value, int larg)
{
	int		i;

	i = 0;
	if (o->with == 'w' && o->pres == 0 && o->dash == 0)
	{
		while (i++ < larg && o->zero == 0)
			ft_putchar(' ');
		if (value < 0 && o->hexa == 0 && o->hexxa == 0)
			ft_putchar('-');
		while (i++ <= larg && o->zero == '0' && o->dot == 0)
			ft_putchar('0');
		if (value < 0 && o->hexa == 0 && o->hexxa == 0)
			ft_putstr(a_argum + 1);
		else
			ft_putstr(a_argum);
		if (larg == 0)
			o->res += (ft_strlen(a_argum));
		else
			o->res += ft_strlen(a_argum) + larg;
	}
	return (0);
}

int			ft_intpreccase(t_printf *o, char *a_argum, int value, int size)
{
	int		i;
	int		prec;
	int		larg;

	prec = ft_int_prec(o, size, value);
	larg = ft_intlarg(o, size, value);
	i = 0;
	if (o->with == 'w' && o->pres != 0 && o->dash == 0)
	{
		if (value >= 0)
		{
			while (i++ < larg)
				ft_putchar(' ');
			i = 0;
			if (o->adr == 1)
				ft_putstr("0x");
			while (i++ < prec)
				ft_putchar('0');
			ft_putstr(a_argum);
		}
		ft_intpreccase2(o, value, larg, prec);
		return (prec + larg + ft_strlen(a_argum));
	}
	return (0);
}

int			ft_intpreccase2(t_printf *o, int value, int larg, int prec)
{
	int		i;

	i = 0;
	if (value < 0 && o->hexa == 0)
	{
		while (i++ < larg && larg >= prec)
			ft_putchar(' ');
		if (value != -2147483648)
			ft_putchar('-');
		i = 0;
		while (i++ < prec)
			ft_putchar('0');
		ft_putnbr(value * -1);
	}
	return (0);
}

int			ft_intothercase(t_printf *o, char *a_argum, int value, int prec)
{
	int		i;

	i = 0;
	if (o->with == 0 && o->nb == 0 && o->dot == '.')
	{
		if (value >= 0)
		{
			while (i++ < prec)
				ft_putchar('0');
			ft_putstr(a_argum);
		}
		else if (value < 0)
		{
			if (value != -2147483648)
				ft_putchar('-');
			i = 0;
			while (i++ < prec)
				ft_putchar('0');
			ft_putnbr(value * -1);
		}
		return (prec + ft_strlen(a_argum));
	}
	return (0);
}
