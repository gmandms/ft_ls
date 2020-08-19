/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:33:26 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:33:35 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_help(char *str, t_printf *p)
{
	while (p->minus == 0 && p->width-- > ft_strlen(str))
	{
		ft_putchar(p->c_width);
		p->i++;
	}
	ft_putstr(str);
	p->i += ft_strlen(str);
	while (p->minus == 1 && p->width-- > ft_strlen(str))
	{
		ft_putchar(p->c_width);
		p->i++;
	}
}
