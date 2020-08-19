/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:26:32 by sbump             #+#    #+#             */
/*   Updated: 2019/11/14 01:48:19 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		len_s1;
	int		len_s2;

	if (!(s1) && !(s2))
		return (NULL);
	if (!(s1))
		return (ft_strdup(s2));
	if (!(s2))
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	while (0 < len_s1--)
		*str++ = *s1++;
	while (0 < len_s2--)
		*str++ = *s2++;
	*str = '\0';
	return (str - len);
}
