/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_format_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:39:10 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:39:12 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int					size_n_ull_o(unsigned long long n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n /= 8;
		i++;
	}
	return (i);
}

char				*perevod_vosm(unsigned long long n)
{
	char	*str;
	char	b;
	int		len;

	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	len = size_n_ull_o(n);
	str = ft_strnew(len);
	len -= 1;
	while (n > 0)
	{
		b = (n % 8) + 48;
		n /= 8;
		str[len--] = b;
	}
	return (str);
}

void				ft_putnbr_ull(unsigned long long n)
{
	unsigned long long	num;
	size_t				ten;
	short				temp;

	if (n == 0)
		return (ft_putchar('0'));
	num = n;
	ten = 1;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	while (num / ten)
		ten = ten * 10;
	ten = ten / 10;
	while (ten)
	{
		temp = num / ten;
		ft_putchar(temp + 48);
		num -= ten * temp;
		ten = ten / 10;
	}
}
