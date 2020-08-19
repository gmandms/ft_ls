/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:34:09 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:34:12 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	help_s(char *p_str, int w, t_printf *p)
{
	if (w > ft_strlen(p_str) && p->minus == 0)
	{
		w -= ft_strlen(p_str);
		p->i += w;
		while (w--)
			ft_putchar(p->c_width);
	}
	ft_putstr(p_str);
	p->i += ft_strlen(p_str);
	if (w > ft_strlen(p_str) && p->minus == 1)
	{
		w -= ft_strlen(p_str);
		p->i += w;
		while (w--)
			ft_putchar(p->c_width);
	}
	free(p_str);
}

void	unstd_s(char *str, t_printf *p, int w, int pr)
{
	char	*p_str;

	if (pr < ft_strlen(str) && p->p_true == 1)
	{
		p_str = malloc(sizeof(char) * pr + 1);
		ft_strncpy(p_str, str, pr);
		p_str[pr] = '\0';
	}
	else
		p_str = ft_strdup(str);
	if (ft_strcmp(str, "(null)") == 0)
		free(str);
	help_s(p_str, w, p);
}

void	format_s(va_list ap, t_printf *p)
{
	char	*str;

	if (ft_strcmp(p->p_str->f_std, p->p_str->f) == 0)
	{
		if (!(str = va_arg(ap, char*)))
			str = ft_strdup("(null)");
		ft_putstr(str);
		p->i += ft_strlen(str);
		if (ft_strcmp(str, "(null)") == 0)
			free(str);
	}
	else
	{
		if (!(str = va_arg(ap, char*)))
			str = ft_strdup("(null)");
		unstd_s(str, p, p->width, p->precision);
		if (ft_strcmp(str, "(null)") == 0)
			free(str);
	}
}
