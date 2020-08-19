/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:32:10 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:32:13 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ret_i(va_list ap, t_printf *p)
{
	long long	n;
	char		*c;

	if ((c = ft_strchr(p->p_str->f, 'l')) && *(c + 1) == 'l')
		n = va_arg(ap, long long);
	else if (ft_strchr(p->p_str->f, 'l'))
		n = va_arg(ap, long);
	else if ((c = ft_strchr(p->p_str->f, 'h'))
	&& *(c + 1) == 'h' && *(c + 2) != 'h')
		n = va_arg(ap, int);
	else if (ft_strchr(p->p_str->f, 'h'))
		n = va_arg(ap, int);
	else
		n = va_arg(ap, int);
	return (n);
}

char			*del_min(char *str)
{
	char	*r_str;

	str++;
	r_str = ft_strdup(str);
	str--;
	free(str);
	return (r_str);
}

void			unstd_i(va_list ap, t_printf *p)
{
	long long int	i;
	char			*str;

	i = ret_i(ap, p);
	str = di_create(i, p);
	if (ft_strchr(str, '-'))
	{
		str = del_min(str);
		p->n_min = 1;
	}
	else
		p->n_min = 0;
	str = di_pr(str, p);
	str = di_source(str, p);
	unstd_print_lli(str, p->width, p);
}

void			format_i(va_list ap, t_printf *p)
{
	int	i;

	if (ft_strcmp(p->p_str->f_std, p->p_str->f) == 0)
	{
		i = va_arg(ap, int);
		ft_putnbr(i);
		p->i += ft_strlen(ft_itoa_lli(i));
	}
	else
		unstd_i(ap, p);
}

void			format_d(va_list ap, t_printf *p)
{
	int		i;
	char	*str;

	if (ft_strcmp(p->p_str->f_std, p->p_str->f) == 0)
	{
		i = va_arg(ap, int);
		str = ft_itoa_lli(i);
		ft_putstr(str);
		p->i += ft_strlen(str);
		free(str);
	}
	else
		unstd_i(ap, p);
}
