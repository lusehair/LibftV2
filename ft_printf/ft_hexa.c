/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:00:47 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/11 12:38:33 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_hexa(t_printf *o, unsigned int argum, char c)
{
	char			*a_argum;
	int				size;
	unsigned int	value;
	int				prec;
	int				larg;

	value = argum;
	a_argum = ft_itoabase(value, 16, c);
	o->vunsign = value;
	size = (int)ft_strlen(a_argum);
	prec = ft_int_prec(o, size, value);
	larg = ft_intlarg(o, size, value);
	if (o->pres == 0 && value == 0 && o->nb == 0 && (o->dot == '.'
		|| o->with == 'w'))
		return (0);
	if (o->dot == 0 && o->with == 0)
	{
		ft_putstr(a_argum);
		o->res += size;
	}
	ft_hexa2(o, a_argum, size, value);
	return (0);
}

int					ft_hexa2(t_printf *o, char *a_argum, int size,
		unsigned int value)
{
	int				prec;
	int				larg;

	prec = ft_int_prec(o, size, value);
	larg = ft_intlarg(o, size, value);
	if (ft_intlargecase(o, a_argum, value, larg) == -2)
		return (0);
	if (value > INT_MAX)
	{
		o->res += ft_hexpreccase(o, a_argum, value, size);
		return (0);
	}
	o->res += ft_intpreccase(o, a_argum, value, size);
	o->res += ft_intothercase(o, a_argum, value, prec);
	if (o->dash == '-')
	{
		o->res += ft_int_dashlarge(o, a_argum, value, larg);
		o->res += ft_int_dashcasucase(o, a_argum, value, size);
	}
	return (0);
}

int					ft_hexpreccase(t_printf *o, char *a_argum,
		unsigned int value, int size)
{
	int				i;
	int				prec;
	int				larg;

	prec = ft_int_prec(o, size, value) - 1;
	larg = ft_intlarg(o, size, value);
	i = 0;
	if (o->dot == '.' && o->dash == 0)
	{
		while (i++ < larg)
			ft_putchar(' ');
		i = 0;
		if (o->adr == 1)
			ft_putstr("0x");
		while (i++ < prec)
			ft_putchar('0');
		ft_putstr(a_argum);
		return (prec + larg + ft_strlen(a_argum));
	}
	return (0);
}
