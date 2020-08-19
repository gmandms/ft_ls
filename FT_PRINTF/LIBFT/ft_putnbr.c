/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 02:36:57 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 19:34:09 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	num;
	size_t	ten;
	short	temp;

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
