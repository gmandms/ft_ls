/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:33:14 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:33:17 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				unstd_print_ull(char *str, int w, int pr, t_printf *p)
{
	if (p->p_true == 1 || p->minus == 1)
		p->c_width = ' ';
	if (w > ft_strlen(str) && w > pr && p->minus == 0)
	{
		w -= ft_strlen(str) > pr ? ft_strlen(str) : pr;
		p->i += w;
		while (w > 0)
		{
			ft_putchar(p->c_width);
			w--;
		}
	}
	help_o_pr(pr, w, str, p);
}

unsigned long long	rec_o_n(va_list ap, t_printf *p)
{
	unsigned long long	n;
	char				*c;

	if ((c = ft_strchr(p->p_str->f, 'l')) && *(c + 1) == 'l')
		n = va_arg(ap, long long);
	else if ((c = ft_strchr(p->p_str->f, 'l')))
		n = va_arg(ap, unsigned long int);
	else if ((c = ft_strchr(p->p_str->f, 'h'))
	&& *(c + 1) == 'h' && *(c + 2) != 'h')
		n = va_arg(ap, int);
	else if ((c = ft_strchr(p->p_str->f, 'h')))
		n = va_arg(ap, int);
	else
		n = va_arg(ap, unsigned int);
	return (n);
}

char				*rec_o_str(unsigned long long n, t_printf *p)
{
	char	*str;
	char	*c;

	if (p->p_true == 1 && p->precision == 0 && n == 0)
		str = ft_strnew(0);
	else if ((c = ft_strchr(p->p_str->f, 'l')) && *(c + 1) == 'l')
		str = perevod_vosm((unsigned long long int)n);
	else if ((c = ft_strchr(p->p_str->f, 'l')))
		str = perevod_vosm((unsigned long int)n);
	else if ((c = ft_strchr(p->p_str->f, 'h'))
	&& *(c + 1) == 'h' && *(c + 2) != 'h')
		str = perevod_vosm((unsigned char)n);
	else if ((c = ft_strchr(p->p_str->f, 'h')))
		str = perevod_vosm((unsigned short int)n);
	else
		str = perevod_vosm(n);
	return (str);
}

void				unstd_o(va_list ap, t_printf *p)
{
	unsigned long long	n;
	char				*str;
	char				*tmp;

	n = rec_o_n(ap, p);
	str = rec_o_str(n, p);
	if (p->n_sign == 1 && ft_strcmp(str, "0") != 0)
	{
		tmp = str;
		str = ft_strjoin("0", str);
		free(tmp);
	}
	unstd_print_ull(str, p->width, p->precision, p);
}

void				format_o(va_list ap, t_printf *p)
{
	unsigned long long	n;
	char				*str;

	if (ft_strcmp(p->p_str->f, p->p_str->f_std) == 0)
	{
		n = va_arg(ap, unsigned int);
		str = perevod_vosm(n);
		ft_putstr(str);
		p->i += ft_strlen(str);
		free(str);
	}
	else
		unstd_o(ap, p);
}
