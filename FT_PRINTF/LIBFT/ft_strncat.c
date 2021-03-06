/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:07:30 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 05:08:44 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *app, size_t n)
{
	char	*s;

	s = dest;
	while (*s != '\0')
		s++;
	while (*app != '\0' && n--)
		*s++ = *app++;
	*s = '\0';
	return (dest);
}
