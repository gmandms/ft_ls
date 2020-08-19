/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_o_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:32:40 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:32:43 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		help_o_pr(int pr, int w, char *str, t_printf *p)
{
	if (pr > ft_strlen(str))
	{
		pr -= ft_strlen(str);
		p->i += pr;
		while (pr > 0)
		{
			ft_putchar('0');
			pr--;
		}
	}
	ft_putstr(str);
	p->i += ft_strlen(str);
	if (w > ft_strlen(str) && w > p->precision && p->minus == 1)
	{
		w -= ft_strlen(str) > p->precision ? ft_strlen(str) : p->precision;
		p->i += w;
		while (w > 0)
		{
			ft_putchar(p->c_width);
			w--;
		}
	}
	free(str);
}
