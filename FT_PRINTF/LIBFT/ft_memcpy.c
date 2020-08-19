/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:53:12 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 04:29:20 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == source)
		return (dest);
	d = (unsigned char*)dest;
	s = (unsigned char*)source;
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}
