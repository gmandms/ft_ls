/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:32:00 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:32:03 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		min_pl(char *str, t_printf *p)
{
	if (ft_strchr(str, '-'))
	{
		if (p->width > ft_strlen(str) && p->c_width == '0' && p->minus == 0)
		{
			*ft_strchr(str, '-') = '0';
			ft_putchar('-');
			p->width--;
		}
	}
	else if (ft_strchr(str, '+'))
	{
		if (p->width > ft_strlen(str) && p->c_width == '0' && p->minus == 0)
		{
			*ft_strchr(str, '+') = '0';
			ft_putchar('+');
			p->width--;
		}
	}
}

long double	ret_n_f(va_list ap, t_printf *p)
{
	long double n;

	if (ft_strchr(p->p_str->f, 'L'))
		n = va_arg(ap, long double);
	else
		n = va_arg(ap, double);
	return (n);
}

void		help_f_while(char *str, t_printf *p)
{
	while (p->minus == 0 && p->width-- > ft_strlen(str))
	{
		ft_putchar(p->c_width);
		p->i += ft_strlen(str);
	}
	ft_putstr(str);
	p->i += ft_strlen(str);
	while (p->minus == 1 && p->width-- > ft_strlen(str))
	{
		ft_putchar(p->c_width);
		p->i += ft_strlen(str);
	}
}

void		unstd_f(va_list ap, t_printf *p)
{
	long double	n;
	char		*str;

	n = ret_n_f(ap, p);
	if (1 / n == 1 / -0.0)
		p->nzero = 1;
	if (n >= 0 && p->plus == 0 && p->space == 1 && p->nzero == 0)
	{
		ft_putchar(' ');
		p->i++;
		if (n != 0)
			p->width--;
		else if (n == 0 && p->p_true == 1 && p->precision == 0)
			p->width--;
	}
	str = double_str(n, p);
	str = ft_pow(str, n, p);
	if (p->p_true == 1 && p->minus == 1)
		p->c_width = ' ';
	min_pl(str, p);
	help_f_while(str, p);
}

void		format_f(va_list ap, t_printf *p)
{
	double	n;
	char	*str;

	if (ft_strcmp(p->p_str->f, p->p_str->f_std) == 0)
	{
		n = va_arg(ap, double);
		if (1 / n == 1 / -0.0)
			p->nzero = 1;
		str = double_str(n, p);
		str = ft_pow(str, n, p);
		ft_putstr(str);
		p->i += ft_strlen(str);
		free(str);
	}
	else
		unstd_f(ap, p);
}
