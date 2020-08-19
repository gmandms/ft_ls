/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:38:52 by sbump             #+#    #+#             */
/*   Updated: 2019/09/29 19:45:20 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_mem(char const *s, char c)
{
	int			i;
	int			a;
	char const	*p;
	char		*str;

	i = 0;
	p = s;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	s = p;
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	a = 0;
	while (a <= i)
	{
		str[a] = '\0';
		a++;
	}
	return (str);
}

static char	**ft_mem_all(char const *s, char c)
{
	int			i;
	char const	*p;
	char		**arr;

	i = 0;
	p = s;
	while (*s != '\0')
	{
		if (*s != c && *s != '\0')
		{
			while (*s != c && *s != '\0')
				s++;
			i++;
		}
		else
			s++;
	}
	s = p;
	if (!(arr = malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	return (arr);
}

static char	**ft_nullar(void)
{
	char	**arr;

	if (!(arr = malloc(sizeof(char*))))
		return (NULL);
	*arr = NULL;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	if (!(arr = ft_mem_all(s, c)))
		return (ft_nullar());
	while (*s != '\0')
	{
		if (*s != c)
		{
			i = 0;
			arr[j] = ft_mem(s, c);
			while (*s != c && *s != '\0')
				arr[j][i++] = *s++;
			arr[j][i] = '\0';
			j++;
		}
		else
			s++;
	}
	arr[j] = NULL;
	return (arr);
}
