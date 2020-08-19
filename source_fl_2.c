/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_fl_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:08:39 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:08:41 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_fl_ints(t_ls *p, int i)
{
	char	*smajor;
	char	*sminor;

	if (ft_strlen(p->fl->n_link[i]) > p->fl->w_n_link)
		p->fl->w_n_link = ft_strlen(p->fl->n_link[i]);
	if (ft_strlen(p->fl->usr_name[i]) > p->fl->w_usr_name)
		p->fl->w_usr_name = ft_strlen(p->fl->usr_name[i]);
	if (ft_strlen(p->fl->gr_name[i]) > p->fl->w_gr_name)
		p->fl->w_gr_name = ft_strlen(p->fl->gr_name[i]);
	if (ft_strlen(p->fl->size[i]) > p->fl->w_size)
		p->fl->w_size = ft_strlen(p->fl->size[i]);
	smajor = ft_itoa(major(p->fl->rdev[i]));
	sminor = ft_itoa(minor(p->fl->rdev[i]));
	if (ft_strlen(smajor) > p->fl->w_major)
		p->fl->w_major = ft_strlen(smajor);
	if (ft_strlen(sminor) > p->fl->w_minor)
		p->fl->w_minor = ft_strlen(sminor);
	free(smajor);
	free(sminor);
}

void	r_link(t_ls *p, struct stat p_stat, char *name, int i)
{
	char	*buf;

	if (p->fl->type[i] == 'l')
	{
		buf = ft_strnew(p_stat.st_size + 1);
		readlink(name, buf, p_stat.st_size + 1);
		p->fl->link[i] = ft_strdup(buf);
		free(buf);
	}
	else
		p->fl->link[i] = ft_strnew(0);
}

void	init_fl_ints(t_flagl *fl)
{
	fl->w_n_link = 0;
	fl->w_usr_name = 0;
	fl->w_gr_name = 0;
	fl->w_size = 0;
	fl->w_dtime = 0;
	fl->w_mtime = 0;
	fl->w_yhtime = 0;
	fl->w_major = 0;
	fl->w_minor = 0;
}

char	*space(int size)
{
	char	*str;
	int		i;

	str = ft_strnew(size);
	i = 0;
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}
