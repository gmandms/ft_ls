/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:39:54 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:39:56 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*rec_n(char *str)
{
	int		i;
	char	*n_str;

	i = 0;
	while (ft_isdigit(str[i]) == 1 && str[i] != '\0')
		i++;
	n_str = ft_strnew(i);
	i = 0;
	while (ft_isdigit(str[i]) == 1 && str[i] != '\0')
	{
		n_str[i] = str[i];
		i++;
	}
	return (n_str);
}

void		rec_w(char *str, t_printf *p)
{
	int		i;
	char	*n_str;

	i = 0;
	p->c_width = ' ';
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
		{
			n_str = rec_n(str + i);
			if (str[i - 1] != '.' && ft_atoi(n_str) == 0)
				p->c_width = '0';
			else if (str[i - 1] != '.')
			{
				if (n_str[0] == '0')
					p->c_width = '0';
				p->width = ft_atoi(n_str);
			}
			i += ft_strlen(n_str);
			free(n_str);
		}
		else
			i++;
	}
}

char		*rec_f_std(char *str)
{
	char	*r_str;

	r_str = ft_strnew(2);
	r_str[0] = str[0];
	r_str[1] = str[ft_strlen(str) - 1];
	return (r_str);
}

int			true_char(char c)
{
	if (ft_isdigit(c) == 1 || c == ' ' || c == '.'
	|| c == '+' || c == '-' || c == '*')
		return (1);
	else if (c == '#' || c == 'h' || c == 'l' ||
	c == 'j' || c == 'z' || c == 't' || c == 'L')
		return (1);
	else if (c == 'd' || c == 'i' || c == 'o' ||
	c == 'u' || c == 'x' || c == 'X')
		return (2);
	else if (c == 's' || c == 'c' || c == 'p')
		return (2);
	else if (c == 'f' || c == '%' || c == 'n')
		return (2);
	else if (c == 'a' || c == 'A' || c == 'e'
	|| c == 'E' || c == 'g' || c == 'G')
		return (2);
	else if (c == 'C' || c == 'D' || c == 'O'
	|| c == 'U' || c == 'F')
		return (3);
	return (0);
}

char		*rec_f(char *format)
{
	int		i;
	char	*str;

	i = 1;
	while (true_char(format[i]) != 0)
	{
		if (true_char(format[i]) == 2)
		{
			i++;
			break ;
		}
		i++;
	}
	if (i <= 0)
		return (NULL);
	str = ft_strnew(i);
	ft_strncpy(str, format, i);
	if (true_char(format[i]) == 3)
		change_c(str, i);
	return (str);
}
