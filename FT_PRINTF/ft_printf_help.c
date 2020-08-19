/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:37:50 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:37:52 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	help_free(t_printf *p)
{
	if (p->ca == 2)
	{
		free(p->p_str->f);
		free(p->p_str);
	}
}

void	help_print(t_printf *p, va_list ap)
{
	if (p->ca == 1)
	{
		print_ap(ap, p);
		free(p->p_str->f_std);
		free(p->p_str->f);
		free(p->p_str);
		create_source(p);
	}
}

int		help_while(char *format, int i, t_printf *p)
{
	while (format[i] && format[i] != '%')
	{
		ft_putchar(format[i]);
		i++;
		p->i++;
	}
	return (i);
}
