/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_main_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:39:45 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:39:46 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	change_c(char *str, int i)
{
	i -= 1;
	if (str[i] == 'C')
		str[i] = 'c';
	else if (str[i] == 'D')
		str[i] = 'd';
	else if (str[i] == 'O')
		str[i] = 'o';
	else if (str[i] == 'U')
		str[i] = 'u';
	else if (str[i] == 'F')
		str[i] = 'f';
}

int		help_rec_pr(char *c, int i)
{
	char	*r_str;

	r_str = ft_strnew(i - 1);
	c++;
	r_str[i - 2] = '\0';
	ft_strncpy(r_str, c, i - 1);
	i = ft_atoi(r_str);
	free(r_str);
	return (i);
}

int		rec_pr(char *str, t_printf *p)
{
	int		i;
	char	*c;

	i = 0;
	if ((c = ft_strchr(str, '.')))
	{
		i++;
		p->p_true = 1;
		if (ft_isdigit(c[i]) == 0)
			return (0);
		while (ft_isdigit(c[i]) == 1)
			i++;
	}
	if (i > 0)
		return (help_rec_pr(c, i));
	p->p_true = 0;
	return (0);
}
