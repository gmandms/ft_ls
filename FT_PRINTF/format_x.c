/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:34:40 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:34:43 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*for_ns_w(char *str, int w, char c, t_printf *p)
{
	char	*r_str;
	char	*x;

	if (c == 'x')
		x = ft_strdup("0x");
	else
		x = ft_strdup("0X");
	w -= ft_strlen(str) + 2;
	r_str = ft_strnew(w);
	if (p->minus == 0)
		r_str = help_for_ns_w_if(r_str, str, x, w);
	else
		r_str = help_for_ns_w_else(r_str, str, x, w);
	free(x);
	return (r_str);
}

void				put_unstd_x(char *str, t_printf *p)
{
	int wr;

	wr = p->width;
	while (p->width > ft_strlen(str)
	&& p->width > p->precision && p->minus == 0)
	{
		ft_putchar(p->c_width);
		p->i++;
		p->width--;
	}
	if (p->minus == 1 &&
	p->width > p->precision && p->precision > ft_strlen(str))
		wr -= p->precision;
	else if (p->minus == 1 && p->width > ft_strlen(str))
		wr -= ft_strlen(str);
	while (p->precision > ft_strlen(str))
	{
		ft_putchar('0');
		p->precision--;
		p->i++;
	}
	help_put_unstd_x(str, p, wr);
}

unsigned long long	ret_n(va_list ap, t_printf *p)
{
	char				*c;
	unsigned long long	n;

	if ((c = ft_strchr(p->p_str->f, 'l')) && *(c + 1) == 'l')
		n = va_arg(ap, unsigned long long int);
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

void				unstd_x(va_list ap, t_printf *p, char c)
{
	unsigned long long	n;
	char				*str;

	n = ret_n(ap, p);
	str = rec_x_str(n, p, c);
	if (p->p_true == 1)
		p->c_width = ' ';
	if (p->n_sign == 1 && p->precision > ft_strlen(str)
	&& p->p_true == 1 && n != 0)
	{
		str = p_pr(str, p, c);
		p->precision = 0;
		p->n_sign = 0;
	}
	if (p->n_sign == 1 && p->width > (ft_strlen(str) + 2)
	&& p->p_true == 0 && p->c_width == '0' && n != 0)
	{
		str = for_ns_w(str, p->width, c, p);
		p->width = 0;
		p->n_sign = 0;
	}
	if (p->n_sign == 1 && n != 0)
		str = n_sign(c, str);
	put_unstd_x(str, p);
}

void				format_x(va_list ap, t_printf *p)
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
		str = perevod_shes(n, 'x');
		ft_putstr(str);
		p->i += ft_strlen(str);
		free(str);
	}
	else
		unstd_x(ap, p, 'x');
}
