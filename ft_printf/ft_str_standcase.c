/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_standcase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:18:21 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/06 16:23:19 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_standstrlarg(t_printf *o, size_t size, char *string)
{
	int i;
	int larg;

	i = 0;
	larg = ft_strlarg(o, size);
	while (i++ < larg)
		ft_putchar(' ');
	ft_putstr(string);
	return (larg + size);
}

int		ft_standstrprec(t_printf *o, size_t size, char *string)
{
	int i;
	int prec;

	i = 0;
	prec = ft_strprec(o, size);
	while (i < prec)
		ft_putchar(string[i++]);
	return (prec);
}

int		ft_standstrlargprec(t_printf *o, size_t size, char *string)
{
	int prec;
	int larg;
	int i;

	i = 0;
	prec = ft_strprec(o, size);
	larg = ft_strlarg(o, size);
	while (i++ < larg)
		ft_putchar(' ');
	i = 0;
	while (i < prec)
		ft_putchar(string[i++]);
	return (larg + prec);
}
