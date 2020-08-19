/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:46:01 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 20:04:51 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char		*dest;
	unsigned char		*dest2;
	const unsigned char	*src;
	const unsigned char	*src2;

	dest = destination;
	src = source;
	if (dest == src)
		return (dest);
	if (dest < src)
		while (n--)
			*dest++ = *src++;
	else
	{
		dest2 = dest + n;
		src2 = src + n;
		while (n--)
			*--dest2 = *--src2;
	}
	return (destination);
}
