/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dashcase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:15:11 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/06 16:18:03 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strdashlarg(t_printf *o, size_t size, char *string)
{
	int i;
	int larg;

	i = 0;
	larg = ft_strlarg(o, size);
	ft_putstr(string);
	while (i++ < larg)
		ft_putchar(' ');
	return (size + larg);
}

int		ft_strdashlarpre(t_printf *o, size_t size, char *string)
{
	int prec;
	int larg;
	int i;

	i = 0;
	prec = ft_strprec(o, size);
	larg = ft_strlarg(o, size);
	while (i < prec)
		ft_putchar(string[i++]);
	i = 0;
	while (i++ < larg)
		ft_putchar(' ');
	return (prec + larg);
}
