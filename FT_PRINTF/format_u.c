/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:34:18 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:34:20 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	rec_u_n(va_list ap, t_printf *p)
{
	unsigned long long	n;
	char				*c;

	if ((c = ft_strchr(p->p_str->f, 'l')) && *(c + 1) == 'l')
		n = va_arg(ap, long long);
	else if (ft_strchr(p->p_str->f, 'l'))
		n = va_arg(ap, unsigned long int);
	else if ((c = ft_strchr(p->p_str->f, 'h'))
	&& *(c + 1) == 'h' && *(c + 2) != 'h')
		n = va_arg(ap, int);
	else if (ft_strchr(p->p_str->f, 'h'))
		n = va_arg(ap, int);
	else
		n = va_arg(ap, unsigned int);
	return (n);
}

char				*rec_u_str(unsigned long long n, t_printf *p)
{
	char	*str;
	char	*c;

	if (p->p_true == 1 && p->precision == 0 && n == 0)
		str = ft_strnew(0);
	else if ((c = ft_strchr(p->p_str->f, 'l')) && *(c + 1) == 'l')
		str = ft_itoa_ull((unsigned long long int)n);
	else if (ft_strchr(p->p_str->f, 'l'))
		str = ft_itoa_ull((unsigned long int)n);
	else if ((c = ft_strchr(p->p_str->f, 'h'))
	&& *(c + 1) == 'h' && *(c + 2) != 'h')
		str = ft_itoa_ull((unsigned char)n);
	else if (ft_strchr(p->p_str->f, 'h'))
		str = ft_itoa_ull((unsigned short int)n);
	else
		str = ft_itoa_ull(n);
	return (str);
}

void				unstd_u(va_list ap, t_printf *p)
{
	unsigned long long int	n;
	char					*str;
	char					*tmp;

	n = rec_u_n(ap, p);
	str = rec_u_str(n, p);
	if (p->n_sign == 1 && ft_strcmp(str, "0") != 0)
	{
		tmp = str;
		str = ft_strjoin("0", str);
		free(tmp);
	}
	unstd_print_ull(str, p->width, p->precision, p);
}

void				format_u(va_list ap, t_printf *p)
{
	unsigned long long	n;
	char				*str;

	if (ft_strcmp(p->p_str->f, p->p_str->f_std) == 0)
	{
		n = va_arg(ap, unsigned int);
		str = ft_itoa_ull(n);
		ft_putstr(str);
		p->i += ft_strlen(str);
		free(str);
	}
	else
		unstd_u(ap, p);
}
