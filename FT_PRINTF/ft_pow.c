/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:35:47 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:35:49 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*hh_pow(char *str, long long i)
{
	char	*r_str;

	if (i == 0 && str[i] != '-')
	{
		r_str = ft_strjoin("1", str);
		free(str);
		return (r_str);
	}
	else if (str[i - 1] && str[i - 1] == '-')
	{
		str[i - 1] = '1';
		r_str = ft_strjoin("-", str);
		free(str);
		return (r_str);
	}
	return (str);
}

int			help_help_pow(long long *i, long long *a, char *str)
{
	*a = str[*i] - 48;
	str[*i] = '0';
	if (str != hh_pow(str, *i))
	{
		str = hh_pow(str, *i);
		return (1);
	}
	return (0);
}

char		*help_pow(char *str, long double n)
{
	long long a;
	long long i;

	i = n;
	a = i % 10;
	i = ft_strlen(str) - 1;
	while (i > -1)
	{
		if (a / 5 > 0)
		{
			if (str[i] == '.')
				i -= 1;
			if (str[i] < '9')
			{
				str[i] += 1;
				break ;
			}
			if (help_help_pow(&i, &a, str) == 1)
				break ;
		}
		else
			break ;
		i--;
	}
	return (str);
}

long double	n_pw(int size, long double n)
{
	long long a;

	a = n;
	n -= a;
	while (size--)
		n *= 10;
	n *= 10;
	return (n);
}

char		*ft_pow(char *str, long double n, t_printf *p)
{
	int	size;

	if (n < 0)
		n *= -1;
	size = ds_size(p);
	n = n_pw(size, n);
	str = help_pow(str, n);
	return (str);
}
