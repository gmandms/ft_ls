/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:02:28 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 04:56:16 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		n;

	i = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	n = 0;
	while (n < i)
	{
		s2[n] = s1[n];
		n++;
	}
	s2[n] = '\0';
	return (s2);
}
