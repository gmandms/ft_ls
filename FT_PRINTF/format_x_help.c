/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:34:29 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:34:32 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*help_for_ns_w_else(char *r, char *str, char *x, int w)
{
	char	*tmp;
	int		i;

	i = 0;
	while (w--)
		r[i++] = ' ';
	tmp = str;
	str = ft_strjoin(x, str);
	free(tmp);
	tmp = r;
	r = ft_strjoin(str, r);
	free(tmp);
	return (r);
}

char				*help_for_ns_w_if(char *r, char *str, char *x, int w)
{
	char	*tmp;
	int		i;

	i = 0;
	while (w--)
		r[i++] = '0';
	tmp = r;
	r = ft_strjoin(x, r);
	free(tmp);
	r = ft_strcat(r, str);
	free(str);
	return (r);
}

void				help_put_unstd_x(char *str, t_printf *p, int wr)
{
	ft_putstr(str);
	p->i += ft_strlen(str);
	if (p->width > ft_strlen(str))
	{
		while (p->minus == 1 && wr)
		{
			ft_putchar(p->c_width);
			p->i++;
			wr--;
		}
	}
	free(str);
}

char				*rec_x_str(unsigned long long n, t_printf *p, char ch)
{
	char	*str;
	char	*c;

	if (p->p_true == 0 && n == 0)
		str = ft_strdup("0");
	else if ((c = ft_strchr(p->p_str->f, 'l')) && *(c + 1) == 'l')
		str = perevod_shes((unsigned long long int)n, ch);
	else if (ft_strchr(p->p_str->f, 'l'))
		str = perevod_shes((unsigned long int)n, ch);
	else if ((c = ft_strchr(p->p_str->f, 'h'))
	&& *(c + 1) == 'h' && *(c + 2) != 'h')
		str = perevod_shes((unsigned char)n, ch);
	else if (ft_strchr(p->p_str->f, 'h'))
		str = perevod_shes((unsigned short int)n, ch);
	else
		str = perevod_shes(n, ch);
	return (str);
}

char				*n_sign(char c, char *str)
{
	char	*r_str;

	if (c == 'x')
		r_str = ft_strjoin("0x", str);
	else if (c == 'X')
		r_str = ft_strjoin("0X", str);
	else
		return (str);
	free(str);
	return (r_str);
}
