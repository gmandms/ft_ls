/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:05:37 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:05:41 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*cr_space(char *str, int size)
{
	free(str);
	str = space(size);
	return (str);
}

void	print_time(t_ls *p, int i)
{
	char	*str_sp;

	str_sp = ft_strnew(0);
	str_sp = cr_space(str_sp, p->fl->w_dtime - ft_strlen(p->fl->d_time[i]));
	ft_printf("%s%s ", str_sp, p->fl->d_time[i]);
	str_sp = cr_space(str_sp, p->fl->w_mtime - ft_strlen(p->fl->m_time[i]));
	ft_printf("%s%s ", str_sp, p->fl->m_time[i]);
	str_sp = cr_space(str_sp, p->fl->w_yhtime - ft_strlen(p->fl->yh_time[i]));
	ft_printf("%s%s ", str_sp, p->fl->yh_time[i]);
	free(str_sp);
}

void	help_flprint(t_ls *p, int i)
{
	char	*tmp;
	char	*s;

	s = ft_strnew(0);
	if (p->fl->type[i] != 'b' && p->fl->type[i] != 'c')
	{
		s = cr_space(s, p->fl->w_size - ft_strlen(p->fl->size[i]));
		ft_printf("%s%s ", s, p->fl->size[i]);
	}
	else
	{
		tmp = ft_itoa(major(p->fl->rdev[i]));
		s = cr_space(s, p->fl->w_major - ft_strlen(tmp));
		ft_printf("%s%d, ", s, major(p->fl->rdev[i]));
		free(tmp);
		tmp = ft_itoa(minor(p->fl->rdev[i]));
		s = cr_space(s, p->fl->w_minor - ft_strlen(tmp));
		ft_printf("%s%d ", s, minor(p->fl->rdev[i]));
		free(tmp);
	}
	free(s);
}

void	flprint(t_ls *p, int i)
{
	char	*s;

	s = ft_strnew(0);
	ft_printf("%c%s  ", p->fl->type[i], p->fl->priotity[i]);
	s = cr_space(s, p->fl->w_n_link - ft_strlen(p->fl->n_link[i]));
	ft_printf("%s%s ", s, p->fl->n_link[i]);
	s = cr_space(s, p->fl->w_usr_name - ft_strlen(p->fl->usr_name[i]));
	ft_printf("%s%s  ", p->fl->usr_name[i], s);
	s = cr_space(s, p->fl->w_gr_name - ft_strlen(p->fl->gr_name[i]));
	ft_printf("%s%s  ", p->fl->gr_name[i], s);
	free(s);
}

void	fl_print(t_ls *p, char **arr_names)
{
	int		i;

	i = 0;
	while (arr_names[i])
	{
		while (p->flag_a == 0 && arr_names[i] && arr_names[i][0] == '.')
			i++;
		if (!arr_names[i])
			break ;
		flprint(p, i);
		help_flprint(p, i);
		print_time(p, i);
		ft_printf("%s", arr_names[i]);
		if (p->fl->type[i] == 'l')
			ft_printf(" -> %s\n", p->fl->link[i]);
		else
			ft_putchar('\n');
		i++;
	}
}
