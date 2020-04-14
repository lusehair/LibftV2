/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:13:20 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/06 18:55:40 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_unsign(t_printf *o, unsigned int argum)
{
	char			*a_argum;
	int				size;
	unsigned int	value;
	int				prec;
	int				larg;

	value = argum;
	a_argum = ft_uitoa(value);
	size = (int)ft_strlen(a_argum);
	prec = ft_unsign_prec(o, size, value);
	larg = ft_unsignlarg(o, size, value);
	if (o->dot == 0 && o->with == 0)
	{
		ft_uputnbr(value);
		o->res += size;
	}
	if (ft_unsignlargecase(o, a_argum, value, larg) == -2)
		return (0);
	o->res += ft_unsignpreccase(o, a_argum, value, size);
	o->res += ft_unsignothercase(o, a_argum, value, prec);
	ft_unsign2(o, a_argum, value, larg);
	return (0);
}

int					ft_unsign2(t_printf *o, char *a_argum, int value, int larg)
{
	int				size;
	int				prec;

	size = (int)ft_strlen(a_argum);
	prec = ft_unsign_prec(o, size, value);
	if (o->dash == '-')
	{
		ft_unsign_dashlarge(o, a_argum, value, larg);
		o->res += ft_unsign_dashcasucase(o, a_argum, larg, prec);
	}
	free(a_argum);
	return (0);
}

int					ft_unsign_prec(t_printf *o, int size, unsigned int val)
{
	int				prec;

	prec = 0;
	if (val < 0)
		size--;
	if (o->pres >= size)
		prec = o->pres - size;
	return (prec);
}

int					ft_unsignlarg(t_printf *o, int size, unsigned int val)
{
	int				larg;
	int				comp;

	if (o->pres > size && (int)val >= 0)
		comp = o->pres;
	else if (o->pres >= size && (int)val < 0)
		comp = o->pres + 1;
	else
		comp = size;
	larg = 0;
	if (o->dot == '.' && o->pres != 0)
	{
		if (val >= 0)
			if (o->nb > comp)
				larg = o->nb - comp;
		if (val < 0)
			if (o->nb > comp)
				larg = o->nb - comp;
	}
	else if (o->nb > size)
		larg = o->nb - size;
	return (larg);
}
