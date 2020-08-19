/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_format_di.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:38:56 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:39:01 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pr_rec(char *str, int size)
{
	char	*pr;
	char	*tmp;

	tmp = str;
	pr = ft_strnew(size);
	while (size > -1)
		pr[size-- - 1] = '0';
	str = ft_strjoin(pr, str);
	free(tmp);
	free(pr);
	return (str);
}

char	*help_unstd_print_lli(char *str, int *w, t_printf *p)
{
	char	*tmp;

	*w -= 1;
	ft_putchar(*str);
	p->i++;
	tmp = str;
	str = ft_strdup(++str);
	free(tmp);
	return (str);
}

void	unstd_print_lli(char *str, int w, t_printf *p)
{
	int		f_minus;

	if (ft_strchr(str, '-'))
		f_minus = 1;
	else
		f_minus = 0;
	if (p->c_width == '0' && w > ft_strlen(str)
	&& (p->plus == 1 || f_minus == 1 || p->space == 1))
		str = help_unstd_print_lli(str, &w, p);
	while (p->minus == 0 && w-- > ft_strlen(str))
	{
		ft_putchar(p->c_width);
		p->i++;
	}
	ft_putstr(str);
	p->i += ft_strlen(str);
	while (p->minus == 1 && w-- > ft_strlen(str))
	{
		ft_putchar(p->c_width);
		p->i++;
	}
	free(str);
}
