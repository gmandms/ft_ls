/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:35:35 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:35:37 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_itoa_op(void)
{
	char *string;

	if ((string = (char*)malloc(1 * sizeof(char) + 1)) == NULL)
		return (NULL);
	string[0] = '0';
	string[1] = '\0';
	return (string);
}

unsigned long long	ft_itoa_num(unsigned long long n)
{
	unsigned long long	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char				*ft_itoa_ull(unsigned long long n)
{
	unsigned long long		i;
	char					*string;
	unsigned long long		super;

	if (n == 0)
		return (ft_itoa_op());
	super = n;
	i = ft_itoa_num(super);
	if ((string = (char*)malloc(i * sizeof(char) + 1)) == NULL)
		return (NULL);
	if (super < 0)
	{
		string[0] = '-';
		super = -super;
	}
	string[i--] = '\0';
	while (super)
	{
		string[i] = super % 10 + 48;
		i--;
		super /= 10;
	}
	return (string);
}
