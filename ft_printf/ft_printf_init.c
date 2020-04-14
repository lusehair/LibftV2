/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:37:03 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/12 16:21:26 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parser(const char *format, t_printf *o, va_list arglist)
{
	int		i;

	i = 0;
	while (format[i] != ' ' && format[i])
	{
		if (ft_convcheck(format[i]) == 1)
			return (0);
		if (format[i] == '%' && ft_flagcheck(format[i + 1]) == 1)
			return (0);
		if (ft_isdigit(format[i]) == 1 && o->dot == 0 && format[i] != '0')
		{
			o->with = 'w';
			o->nb = ft_atoi(&format[i]);
			if (o->nb == 0)
				o->with = 0;
			while (ft_isdigit(format[i]) == 1)
				i++;
		}
		ft_parser2(format, o, arglist, &i);
		ft_parser3(o);
		i++;
	}
	return (0);
}

int			ft_parser2(const char *format, t_printf *o, va_list arglist, int *i)
{
	if (format[*i] == '*' && format[*i - 1] != '.')
	{
		o->nb = (int)va_arg(arglist, int);
		if (o->nb == 0)
			o->zero = '0';
		else
			o->with = 'w';
	}
	if (format[*i] == '.' && ft_convcheck(format[*i - 1]) == 0)
		o->dot = '.';
	if (ft_isdigit(format[*i]) == 1 && o->dot == '.')
	{
		o->pres = ft_atoi(format + *i);
		while (ft_isdigit(format[*i]) == 1)
			*i = *i + 1;
	}
	if (format[*i] == '*' && format[*i - 1] == '.')
		o->pres = (int)va_arg(arglist, int);
	if (format[*i] == '0' && format[*i - 1] == '%')
		o->zero = '0';
	if (format[*i] == '-')
		o->dash = '-';
	return (0);
}

void		ft_parser3(t_printf *o)
{
	if (o->with == 'w' && o->nb < 0)
	{
		o->dash = '-';
		o->nb *= -1;
	}
	if (o->dash == '-' && o->zero == '0')
		o->zero = 0;
	if (o->pres < 0)
	{
		o->pres = 0;
		o->dot = 0;
	}
}

void		ft_conv(const char *format, t_printf *o, int *i)
{
	(*i)++;
	while (format[*i] && format[*i] != ' ')
	{
		if (format[*i] == '%')
		{
			o->perc = 1;
			return ;
		}
		if (format[*i] == 'i' || format[*i] == 'd')
		{
			o->integer = 1;
			return ;
		}
		if (format[*i] == 's')
		{
			o->string = 1;
			return ;
		}
		if (ft_conv2(format, o, i) == 1)
			return ;
		(*i)++;
	}
}

int			ft_conv2(const char *format, t_printf *o, int *i)
{
	if (o->dash == '-' && o->with == 0)
		o->dash = 0;
	if (format[*i] == 'p')
	{
		o->adr = 1;
		return (1);
	}
	if (format[*i] == 'u')
	{
		o->unsign = 1;
		return (1);
	}
	if (format[*i] == 'c')
	{
		o->character = 1;
		return (1);
	}
	if (format[*i] == 'x')
	{
		o->hexa = 1;
		return (1);
	}
	return ((o->hexxa = (format[*i] == 'X')));
}
