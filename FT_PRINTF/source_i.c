/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:39:34 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:39:36 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*di_pr(char *str, t_printf *p)
{
	char	*r_str;

	if (p->precision > ft_strlen(str))
		r_str = pr_rec(str, (p->precision - ft_strlen(str)));
	else
		return (str);
	return (r_str);
}

char	*di_create(long long int i, t_printf *p)
{
	char	*str;
	char	*c;

	if (i == 0 && p->precision == 0 && p->p_true == 1)
		str = ft_strnew(0);
	else if ((c = ft_strchr(p->p_str->f, 'l')) && *(c + 1) == 'l')
		str = ft_itoa_lli((long long)i);
	else if (ft_strchr(p->p_str->f, 'l'))
		str = ft_itoa_lli((long)i);
	else if ((c = ft_strchr(p->p_str->f, 'h'))
	&& *(c + 1) == 'h' && *(c + 2) != 'h')
		str = ft_itoa_lli((signed char)i);
	else if (ft_strchr(p->p_str->f, 'h'))
		str = ft_itoa_lli((short int)i);
	else
		str = ft_itoa_lli(i);
	return (str);
}

char	*di_source(char *str, t_printf *p)
{
	char	*r_str;

	if (p->p_true == 1 || p->minus == 1)
		p->c_width = ' ';
	if (p->n_min == 1 && !ft_strchr(str, '-'))
		r_str = ft_strjoin("-", str);
	else if (p->space == 1 && p->n_min == 0 && p->plus == 0)
		r_str = ft_strjoin(" ", str);
	else if (p->plus == 1 && p->n_min == 0)
		r_str = ft_strjoin("+", str);
	else
		return (str);
	free(str);
	return (r_str);
}
