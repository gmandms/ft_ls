/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:38:20 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:38:23 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_source(t_printf *p)
{
	p->minus = 0;
	p->p_true = 0;
	p->precision = 0;
	p->width = 0;
	p->plus = 0;
	p->n_sign = 0;
	p->space = 0;
	p->nzero = 0;
}

void	help_create_format(t_printf *p)
{
	if (ft_strchr(p->p_str->f, '-'))
	{
		p->minus = 1;
		p->c_width = ' ';
	}
	if (ft_strchr(p->p_str->f, '+'))
		p->plus = 1;
	if (ft_strchr(p->p_str->f, '#'))
		p->n_sign = 1;
	if (ft_strchr(p->p_str->f, ' '))
		p->space = 1;
}

int		create_format(t_printf *p, char *format)
{
	int i;

	i = 0;
	p->ca = 0;
	p->p_str->f = rec_f(format + i);
	if (ft_strlen(p->p_str->f) > 1)
	{
		p->p_str->f_std = rec_f_std(p->p_str->f);
		p->ca = 1;
	}
	else if (p->p_str->f_std && ft_strlen(p->p_str->f) <= 1)
		p->ca = 2;
	p->precision = rec_pr(p->p_str->f, p);
	rec_w(p->p_str->f, p);
	help_create_format(p);
	i += ft_strlen(p->p_str->f);
	return (i);
}

int		ft_printf(char *format, ...)
{
	va_list		ap;
	int			i;
	t_printf	*p;

	i = 0;
	p = malloc(sizeof(t_printf));
	create_source(p);
	p->i = 0;
	p->ca = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			p->p_str = malloc(sizeof(t_str));
			i += create_format(p, format + i);
		}
		help_print(p, ap);
		i = help_while(format, i, p);
		help_free(p);
	}
	va_end(ap);
	i = p->i;
	free(p);
	return (i);
}
