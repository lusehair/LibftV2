/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:58:34 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/12 16:16:43 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlarg(t_printf *o, size_t size)
{
	size_t	i;
	int		larg;

	i = 0;
	larg = 0;
	if (o->pres != 0 && o->dot == '.')
	{
		if (o->pres < (int)size)
			return (o->nb - o->pres);
	}
	if ((size_t)o->nb >= size)
		larg = o->nb - (int)size;
	return (larg);
}

int			ft_strprec(t_printf *o, size_t size)
{
	size_t	i;
	int		prec;

	i = 0;
	prec = 0;
	if ((size_t)o->pres <= size)
		prec = (int)o->pres;
	else
		prec = (int)size;
	return (prec);
}

int			ft_ifchar(t_printf *o, char *argum)
{
	char	*string;
	size_t	size;

	if (argum == NULL)
		string = ft_strdup("(null)");
	else
		string = ft_strdup(argum);
	size = ft_strlen(string);
	if (o->nb != 0 && o->with == 'w' && o->dot == '.' && o->pres == 0
			&& o->zero == 0)
	{
		ft_ifint(o, 0);
		return (0);
	}
	if (o->nb == 0 && o->pres == 0 && o->dot == '.' && o->pres == 0)
	{
		if (argum != NULL)
			free(string);
		return (0);
	}
	ft_ifchar2(o, string, size);
	return (0);
}

int			ft_ifchar2(t_printf *o, char *string, size_t size)
{
	if (o->with == 'w' && o->nb > 0 && o->dot != '.' && o->zero == '0')
		ft_intlargecase(o, string, 1, ft_strlarg(o, size));
	if (o->pres == 0 && o->with == 0 && o->dot != '.')
	{
		ft_putstr(string);
		o->res += size;
	}
	if (o->dash == '-')
	{
		if (o->with == 'w' && o->nb != 0 && o->pres == 0)
			o->res += ft_strdashlarg(o, size, string);
		else if (o->with == 'w' && o->dot == '.' && o->pres != 0 && o->nb != 0)
			o->res += ft_strdashlarpre(o, size, string);
		else if (o->with != 'w' && o->dot == '.')
			o->res += ft_standstrprec(o, size, string);
	}
	ft_ifchar3(o, string, size);
	return (0);
}

int			ft_ifchar3(t_printf *o, char *string, size_t size)
{
	if (o->dash == 0)
	{
		if (o->with == 'w' && o->nb != 0 && o->pres == 0 && o->zero != '0')
			o->res += ft_standstrlarg(o, size, string);
		else if (o->with != 'w' && o->dot == '.' && o->pres != 0)
			o->res += ft_standstrprec(o, size, string);
		else if (o->with == 'w' && o->dot == '.' && o->pres != 0 && o->nb != 0)
			o->res += ft_standstrlargprec(o, size, string);
	}
	if (string != NULL)
		free(string);
	return (0);
}
