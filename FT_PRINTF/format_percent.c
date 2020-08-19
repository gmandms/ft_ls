/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:33:57 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:33:59 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_percent(t_printf *p)
{
	if (ft_strcmp(p->p_str->f, p->p_str->f_std) == 0)
	{
		ft_putchar('%');
		p->i++;
	}
	else
	{
		if (p->minus == 1)
			p->c_width = ' ';
		while (p->minus == 0 && p->width-- > 1)
		{
			ft_putchar(p->c_width);
			p->i++;
		}
		ft_putchar('%');
		p->i++;
		while (p->minus == 1 && p->width-- > 1)
		{
			ft_putchar(p->c_width);
			p->i++;
		}
	}
}
