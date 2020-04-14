/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign_standcase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:45:13 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/10 14:02:28 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsignlargecase(t_printf *o, char *a_arg, unsigned int val, int lar)
{
	int i;

	i = 0;
	if (o->nb == 0 && o->dot == '.' && o->pres == 0 && val == 0 && o->dash == 0)
	{
		free(a_arg);
		o->res += 0;
		return (-2);
	}
	if (o->dot == '.' && o->nb != 0 && o->pres == 0 && val == 0)
	{
		while (i++ <= lar)
			ft_putchar(' ');
		o->res += o->nb;
		free(a_arg);
		return (-2);
	}
	ft_unsignlargecase2(o, a_arg, lar);
	return (0);
}

int		ft_unsignlargecase2(t_printf *o, char *a_argum, int larg)
{
	int i;

	i = 0;
	if (o->with == 'w' && o->dot == 0 && o->dash == 0)
	{
		while (i++ < larg && o->zero != '0')
			ft_putchar(' ');
		while (i++ <= larg && o->zero == '0')
			ft_putchar('0');
		ft_putstr(a_argum);
		o->res += larg + ft_strlen(a_argum);
	}
	return (0);
}

int		ft_unsignpreccase(t_printf *o, char *a_argum, unsigned int value,
		int size)
{
	int	i;
	int	prec;
	int	larg;

	prec = ft_unsign_prec(o, size, value);
	larg = ft_unsignlarg(o, size, value);
	i = 0;
	if (o->with == 'w' && o->dot == '.' && o->dash == 0)
	{
		if (value >= 0)
		{
			while (i++ < larg && (larg >= prec || value == 0))
				ft_putchar(' ');
			i = 0;
			while (i++ < prec)
				ft_putchar('0');
			ft_putstr(a_argum);
		}
		return (prec + larg + size);
	}
	return (0);
}

int		ft_unsignothercase(t_printf *o, char *a_arg, unsigned int val, int pre)
{
	int i;

	i = 0;
	if (o->with == 0 && o->nb == 0 && o->dot == '.')
	{
		if (val >= 0)
		{
			while (i++ < pre)
				ft_putchar('0');
			ft_putstr(a_arg);
		}
		return (pre + ft_strlen(a_arg));
	}
	return (0);
}
