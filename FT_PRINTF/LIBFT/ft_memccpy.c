/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:53:12 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 04:41:28 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		tmp;

	tmp = (unsigned char)c;
	d = (unsigned char*)dest;
	s = (unsigned char*)source;
	while (n--)
	{
		*d++ = *s++;
		if (*(d - 1) == tmp)
			return (d);
	}
	return (NULL);
}
