/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:23:18 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 03:26:22 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	a;
	size_t	b;
	size_t	res;

	a = 0;
	while (dest[a] != '\0')
		a++;
	res = 0;
	while (src[res] != '\0')
		res++;
	if (n <= a)
		res += n;
	else
		res += a;
	b = 0;
	while (src[b] != '\0' && a + 1 < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (res);
}
