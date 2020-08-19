/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:31:38 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:31:46 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_c(char c, t_printf *p)
{
	ft_putchar(c);
	p->i++;
}

void	format_c(va_list ap, t_printf *p)
{
	unsigned char c;

	c = va_arg(ap, int);
	if (ft_strcmp(p->p_str->f, p->p_str->f_std) == 0)
		put_c(c, p);
	else
	{
		if (p->width > 1)
			p->width--;
		else
			p->width = 0;
		while (p->width > 0 && p->minus == 0)
		{
			ft_putchar(p->c_width);
			p->i++;
			p->width--;
		}
		put_c(c, p);
		while (p->width-- > 0 && p->minus == 1)
		{
			ft_putchar(p->c_width);
			p->i++;
		}
	}
}
