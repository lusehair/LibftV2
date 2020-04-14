/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:05:21 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/06 19:59:32 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_adress(t_printf *o, unsigned long long int argum)
{
	const char	*addr_str;
	char		*a_argum;

	o->aadr = argum;
	addr_str = ft_aitoabase((long long int)(o->aadr), 16, 'a');
	if (o->aadr == 0 && o->dot != '.')
	{
		a_argum = ft_calloc(sizeof(char), 4);
		ft_strlcpy(a_argum, "0x0", 3);
		addr_str = NULL;
	}
	else if (o->aadr == 0 && o->dot == '.' && o->pres == 0)
	{
		a_argum = ft_calloc(sizeof(char), 3);
		ft_strlcpy(a_argum, "0x", 2);
		o->dot = 0;
		addr_str = NULL;
	}
	else
		a_argum = ft_adress2(o, addr_str);
	ft_adress3(o, a_argum, addr_str);
	return (0);
}

char			*ft_adress2(t_printf *o, const char *addr_str)
{
	char		*a_argum;

	o->size = ft_strlen(addr_str) + 3;
	if (o->dot == '.' && o->pres < (int)o->size)
	{
		o->dot = 0;
		o->pres = 0;
	}
	a_argum = ft_strjoin("0x", addr_str);
	return (a_argum);
}

void			ft_adress3(t_printf *o, char *a_argum, const char *addr_str)
{
	if (o->dot == 0)
		ft_ifchar(o, a_argum);
	else
	{
		if (o->aadr != 0)
			o->size = o->size - 3;
		else
			o->size = 1;
		o->with = 'w';
		o->nb = 0;
		o->res += ft_intpreccase(o, (char*)addr_str, 1, o->size) + 2;
	}
}
