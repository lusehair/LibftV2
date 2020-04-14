/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:55:05 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/06 17:00:00 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_standcharlarg(t_printf *o, size_t size, char c)
{
	int		i;
	int		larg;

	i = 0;
	larg = ft_strlarg(o, size);
	while (i++ < larg && o->zero != '0')
		ft_putchar(' ');
	while (i++ <= larg && o->perc == 1 && o->zero == '0')
		ft_putchar('0');
	ft_putchar(c);
	o->res += larg + 1;
}

void		ft_chardashlarg(t_printf *o, size_t size, char c)
{
	int		i;
	int		larg;

	i = 0;
	larg = ft_strlarg(o, size);
	ft_putchar(c);
	while (i++ < larg)
		ft_putchar(' ');
	o->res += larg + 1;
}

void		ft_letter(t_printf *o, int argum)
{
	char	c;

	c = argum;
	if (o->dash == '-')
	{
		if (o->with == 'w' && o->nb != 0 && o->pres == 0)
			ft_chardashlarg(o, 1, c);
	}
	else if (o->dash == 0)
	{
		if (o->dash == 0 && o->pres == 0 && o->nb == 0)
		{
			ft_putchar(c);
			o->res += 1;
		}
		else if (o->with == 'w' && o->nb != 0)
			ft_standcharlarg(o, 1, c);
	}
}
