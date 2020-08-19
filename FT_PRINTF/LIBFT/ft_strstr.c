/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:36:04 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 06:17:18 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str2, const char *str1)
{
	int		i;
	int		j;

	i = 0;
	if (str1[i] == '\0')
		return ((char*)str2);
	while (str2[i] != '\0')
	{
		j = 0;
		while (str1[j] == str2[i + j])
		{
			if (str1[j + 1] == '\0')
				return ((char*)str2 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
