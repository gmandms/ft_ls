/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:35:23 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:35:25 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_itoa_op(void)
{
	char *string;

	if ((string = (char*)malloc(1 * sizeof(char) + 1)) == NULL)
		return (NULL);
	string[0] = '0';
	string[1] = '\0';
	return (string);
}

static	int		ft_itoa_num(long n)
{
	long	i;

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

char			*ft_itoa_lli(long long int n)
{
	long long int		i;
	char				*string;
	long long int		super;
	long long			a;

	if (n == 0)
		return (ft_itoa_op());
	super = n;
	i = ft_itoa_num(super);
	if ((string = (char*)malloc(i * sizeof(char) + 1)) == NULL)
		return (NULL);
	if (super < 0)
		string[0] = '-';
	string[i--] = '\0';
	while (super)
	{
		a = super % 10;
		if (a < 0)
			a *= -1;
		string[i] = a + 48;
		i--;
		super /= 10;
	}
	return (string);
}
