/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:35:36 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/10 14:54:28 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_o_printfreset(t_printf *reseter)
{
	reseter->dash = 0;
	reseter->zero = 0;
	reseter->dot = 0;
	reseter->nb = 0;
	reseter->with = 0;
	reseter->pres = 0;
	reseter->integer = 0;
	reseter->string = 0;
	reseter->adr = 0;
	reseter->unsign = 0;
	reseter->character = 0;
	reseter->hexa = 0;
	reseter->hexxa = 0;
	reseter->perc = 0;
	reseter->aadr = 0;
	reseter->size = 0;
	reseter->vunsign = 0;
}

int				ft_flagcheck(char c)
{
	int			i;
	const char	*flag;

	i = 0;
	flag = "c%spdiuxX*0123456789-.";
	while (flag[i])
		if (c == flag[i++])
			return (1);
	return (0);
}

int				ft_convcheck(char c)
{
	int			i;
	const char	*flag;

	i = 0;
	flag = "cspdiuxX";
	while (flag[i])
		if (c == flag[i++])
			return (1);
	return (0);
}

void			ft_domagic(t_printf *o, va_list arglist)
{
	if (o->pres < 0)
	{
		o->pres = 0;
		o->dot = 0;
	}
	if (o->perc == 1)
		ft_letter(o, '%');
	if (o->string == 1)
		ft_ifchar(o, (char *)va_arg(arglist, char *));
	else if (o->integer == 1)
		ft_ifint(o, (int)va_arg(arglist, int));
	else if (o->unsign == 1)
		ft_unsign(o, (unsigned int)va_arg(arglist, unsigned int));
	else if (o->adr == 1)
		ft_adress(o, (long long int)va_arg(arglist, unsigned long long int));
	else if (o->hexa == 1)
		ft_hexa(o, (unsigned int)va_arg(arglist, unsigned int), 'a');
	else if (o->hexxa == 1)
		ft_hexa(o, (unsigned int)va_arg(arglist, unsigned int), 'A');
	else if (o->character == 1)
		ft_letter(o, (int)va_arg(arglist, int));
}

int				ft_printf(const char *format, ...)
{
	int			i;
	va_list		arglist;
	t_printf	option;

	i = 0;
	va_start(arglist, format);
	option.res = 0;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			ft_putchar(format[i++]);
			option.res++;
		}
		if (format[i] && format[i] == '%')
		{
			ft_o_printfreset(&option);
			ft_parser(&format[i + 1], &option, arglist);
			ft_conv(format, &option, &i);
			ft_domagic(&option, arglist);
		}
		i += !!format[i];
	}
	va_end(arglist);
	return (option.res);
}
