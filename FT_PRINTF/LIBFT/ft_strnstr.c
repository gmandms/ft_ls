/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:13:05 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 18:12:09 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str2, const char *str1, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;
	size_t	a;

	s2 = (char*)str2;
	s1 = (char*)str1;
	if (!(a = 0) && *str1 == '\0')
		return ((char*)str2);
	while (s2[a] != '\0' && a < n)
	{
		i = 0;
		while (s1[i] == s2[i + a] && s1[i] != '\0' && i + a < n)
			i++;
		if (s1[i] == '\0')
			return ((char*)(s2 + a));
		a++;
	}
	return (NULL);
}
