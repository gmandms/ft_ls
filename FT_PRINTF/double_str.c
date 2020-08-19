/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:30:58 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:31:21 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*new_str(long double *n, t_printf *p)
{
	char	*str;

	if (*n < 0 || p->nzero == 1)
	{
		*n *= -1;
		str = ft_strdup("-");
	}
	else if (p->plus == 1 && n >= 0)
		str = ft_strdup("+");
	else
		str = ft_strnew(0);
	return (str);
}

int		ds_size(t_printf *p)
{
	int size;

	if (p->p_true == 0)
		size = 6;
	else
		size = p->precision;
	return (size);
}

char	*ds_strjoin_itoa(char *str, long long a)
{
	char	*r_str;
	char	*str2;

	str2 = ft_itoa_lli(a);
	r_str = ft_strjoin(str, str2);
	free(str2);
	free(str);
	return (r_str);
}

char	*point_str(char *str, int size, long long a)
{
	char	*r_str;
	char	*str2;
	int		b;

	str2 = ft_strnew(size);
	while (a > 0)
	{
		b = a % 10;
		str2[size - 1] = b + 48;
		a /= 10;
		size--;
	}
	while (size - 1 > -1)
	{
		str2[size - 1] = '0';
		size--;
	}
	r_str = ft_strjoin(str, str2);
	free(str2);
	free(str);
	return (r_str);
}

char	*double_str(long double n, t_printf *p)
{
	char			*str;
	long long		a;
	int				size;
	int				b;

	str = new_str(&n, p);
	if (n == 0 && p->p_true == 0 && p->nzero == 0)
		return (ft_strdup("0.000000"));
	size = ds_size(p);
	a = n;
	n -= a;
	str = ds_strjoin_itoa(str, a);
	b = size;
	while (size)
	{
		n *= 10;
		size--;
	}
	a = n;
	if (p->precision == 0 && p->p_true == 1 && p->n_sign == 0)
		return (str);
	str = ft_strjoin(str, ".");
	str = point_str(str, b, a);
	return (str);
}
