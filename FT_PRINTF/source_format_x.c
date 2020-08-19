/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_format_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:39:19 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:39:21 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	for_x(int a)
{
	char c;

	if (a == 10)
		c = 'a';
	if (a == 11)
		c = 'b';
	if (a == 12)
		c = 'c';
	if (a == 13)
		c = 'd';
	if (a == 14)
		c = 'e';
	if (a == 15)
		c = 'f';
	return (c);
}

char	for_xx(int a)
{
	char c;

	if (a == 10)
		c = 'A';
	if (a == 11)
		c = 'B';
	if (a == 12)
		c = 'C';
	if (a == 13)
		c = 'D';
	if (a == 14)
		c = 'E';
	if (a == 15)
		c = 'F';
	return (c);
}

int		size_n_ull_x(unsigned long long n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*perevod_shes(unsigned long long n, char x)
{
	char	c;
	char	*str;
	int		len;
	int		a;

	len = size_n_ull_x(n);
	str = ft_strnew(len);
	len -= 1;
	while (n > 0)
	{
		a = n % 16;
		n /= 16;
		if (a > 9 && x == 'x')
			c = for_x(a);
		else if (a > 9 && x == 'X')
			c = for_xx(a);
		else
			c = a + 48;
		str[len--] = c;
	}
	return (str);
}
