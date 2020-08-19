/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:16:28 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 17:59:37 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	if (ch == 0)
		return ((char*)s);
	while (*s != (char)ch && s != str)
		s--;
	if (*s == ch)
		return ((char*)s);
	return (NULL);
}
