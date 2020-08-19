/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:33:45 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:33:48 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*rec_p_str(void *pointer)
{
	char				*str;
	unsigned long long	n;

	if (pointer == NULL)
		str = ft_strdup("0");
	else
	{
		n = (unsigned long int)pointer;
		str = perevod_shes(n, 'x');
	}
	return (str);
}

char	*str_0x(char *str, char c)
{
	char	*r_str;

	if (c == 'x')
		r_str = ft_strjoin("0x", str);
	else if (c == 'X')
		r_str = ft_strjoin("0X", str);
	else
		return (NULL);
	free(str);
	return (r_str);
}

char	*p_pr(char *str, t_printf *p, char c)
{
	char	*r_str;
	int		pr;

	if (p->precision == 0)
		return ("0x");
	pr = p->precision - ft_strlen(str);
	if (pr <= 0)
		return (str_0x(str, 'x'));
	r_str = ft_strnew(pr);
	while (--pr > -1)
		r_str[pr] = '0';
	ft_strcat(r_str, str);
	free(str);
	if (c == 'x')
		r_str = str_0x(r_str, 'x');
	else if (c == 'X')
		r_str = str_0x(r_str, 'X');
	return (r_str);
}

void	unstd_p(void *pointer, t_printf *p)
{
	char				*str;

	str = rec_p_str(pointer);
	if (p->p_true == 1)
		str = p_pr(str, p, 'x');
	else if (p->c_width == ' ')
		str = str_0x(str, 'x');
	else if (p->c_width == '0')
		p->width -= 2;
	p_help(str, p);
	if (p->c_width == '0')
	{
		ft_putstr("0x");
		p->i += 2;
	}
}

void	format_p(va_list ap, t_printf *p)
{
	void	*pointer;

	pointer = va_arg(ap, void*);
	if (ft_strcmp(p->p_str->f_std, p->p_str->f) == 0)
	{
		if (pointer == NULL)
		{
			ft_putstr("0x0");
			p->i += 3;
			return ;
		}
		p->i += ft_printf("%#lx", pointer);
	}
	else
		unstd_p(pointer, p);
}
