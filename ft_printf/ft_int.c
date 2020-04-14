/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:23:49 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/10 15:04:59 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_ifint(t_printf *o, int argum)
{
	char	*a_argum;
	int		size;
	int		value;
	int		prec;
	int		larg;

	value = argum;
	a_argum = ft_itoa((int)argum);
	size = (int)ft_strlen(a_argum);
	prec = ft_int_prec(o, size, value);
	larg = ft_intlarg(o, size, value);
	if (o->dot == '.' && o->pres == 0 && value == 0 && o->nb == 0)
		return (0);
	if (o->dot == 0 && o->with == 0)
	{
		ft_putstr(a_argum);
		o->res += size;
	}
	if (ft_intlargecase(o, a_argum, value, larg) == -2)
		return (0);
	o->res += ft_intpreccase(o, a_argum, value, size);
	o->res += ft_intothercase(o, a_argum, value, prec);
	ft_init2(o, a_argum, value, larg);
	return (0);
}

int			ft_init2(t_printf *o, char *a_argum, int value, int larg)
{
	int		size;

	size = (int)ft_strlen(a_argum);
	if (o->dash == '-')
	{
		o->res += ft_int_dashlarge(o, a_argum, value, larg);
		o->res += ft_int_dashcasucase(o, a_argum, value, size);
	}
	free(a_argum);
	return (0);
}

int			ft_int_prec(t_printf *o, int size, int value)
{
	int		prec;

	prec = 0;
	if (value < 0)
		size--;
	if (o->pres >= size)
	{
		prec = o->pres - size;
	}
	return (prec);
}

int			ft_intlarg(t_printf *o, int size, int value)
{
	int		larg;
	int		comp;

	if (o->pres > size && value >= 0)
		comp = o->pres;
	else if (o->pres >= size && value < 0)
		comp = o->pres + 1;
	else
		comp = size;
	larg = 0;
	if (o->dot == '.' && o->pres != 0)
	{
		if (value >= 0)
			if (o->nb > comp)
				larg = o->nb - comp;
		if (value < 0)
			if (o->nb > comp)
				larg = o->nb - comp;
	}
	else if (o->nb > size)
		larg = o->nb - size;
	return (larg);
}
