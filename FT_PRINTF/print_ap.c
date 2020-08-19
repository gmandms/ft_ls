/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:38:39 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:38:43 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_w(int w, t_printf *p)
{
	while (w-- > 0)
		ft_putchar(p->c_width);
}

void	print_ap(va_list ap, t_printf *p)
{
	if (ft_strcmp(p->p_str->f_std, "%c") == 0)
		format_c(ap, p);
	else if (ft_strcmp(p->p_str->f_std, "%s") == 0)
		format_s(ap, p);
	else if (ft_strcmp(p->p_str->f_std, "%p") == 0)
		format_p(ap, p);
	else if (ft_strcmp(p->p_str->f_std, "%d") == 0)
		format_d(ap, p);
	else if (ft_strcmp(p->p_str->f_std, "%i") == 0)
		format_i(ap, p);
	else if (ft_strcmp(p->p_str->f_std, "%o") == 0)
		format_o(ap, p);
	else if (ft_strcmp(p->p_str->f_std, "%u") == 0)
		format_u(ap, p);
	else if (ft_strcmp(p->p_str->f_std, "%x") == 0)
		format_x(ap, p);
	else if (ft_strcmp(p->p_str->f_std, "%X") == 0)
		format_xx(ap, p);
	else if (ft_strcmp(p->p_str->f_std, "%f") == 0)
		format_f(ap, p);
	else if (ft_strcmp(p->p_str->f_std, "%%") == 0)
		format_percent(p);
	else if (ft_strlen(p->p_str->f) > 1)
		print_w(p->width - 1, p);
}
