/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:58:48 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 20:31:26 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;

	if (n == 0)
		return (0);
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	while ((*a1 && (*a1 == *a2)) && --n)
	{
		if (*a1 != *a2)
			return (*a1 - *a2);
		a1++;
		a2++;
	}
	return (*a1 - *a2);
}
