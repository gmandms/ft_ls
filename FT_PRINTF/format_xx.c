/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_xx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:34:51 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:34:54 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_xx(va_list ap, t_printf *p)
{
	unsigned long long	n;
	char				*str;

	if (ft_strcmp(p->p_str->f, p->p_str->f_std) == 0)
	{
		n = va_arg(ap, unsigned int);
		if (n == 0)
		{
			ft_putnbr(0);
			p->i++;
			return ;
		}
		str = perevod_shes(n, 'X');
		ft_putstr(str);
		p->i += ft_strlen(str);
		free(str);
	}
	else
		unstd_x(ap, p, 'X');
}
