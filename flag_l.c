/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:06:06 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:06:09 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			**file_names(char **targets, int size)
{
	char	**arr_names;
	int		i;

	arr_names = malloc(sizeof(char*) * size + 1);
	arr_names[size] = NULL;
	i = 0;
	while (i < size)
	{
		arr_names[i] = ft_strdup(targets[i]);
		i++;
	}
	return (arr_names);
}

t_flagl			*create_fl(int size)
{
	t_flagl *fl;

	fl = malloc(sizeof(t_flagl));
	init_fl_ints(fl);
	fl->type = malloc(sizeof(char) * size);
	fl->priotity = malloc(sizeof(char*) * size);
	fl->n_link = malloc(sizeof(char*) * size);
	fl->usr_name = malloc(sizeof(char*) * size);
	fl->gr_name = malloc(sizeof(char*) * size);
	fl->size = malloc(sizeof(char*) * size);
	fl->d_time = malloc(sizeof(char*) * size);
	fl->m_time = malloc(sizeof(char*) * size);
	fl->yh_time = malloc(sizeof(char*) * size);
	fl->link = malloc(sizeof(char*) * size);
	fl->rdev = malloc(sizeof(int) * size);
	return (fl);
}

blkcnt_t		record_data(char *name, t_ls *p, int i)
{
	struct stat		p_stat;
	blkcnt_t		block;

	if (lstat(name, &p_stat) == -1)
	{
		perror("record data");
		return (-1);
	}
	p->fl->type[i] = r_type(name);
	p->fl->priotity[i] = r_priority(p_stat);
	p->fl->n_link[i] = ft_itoa_ull(p_stat.st_nlink);
	p->fl->usr_name[i] = r_usrname(p_stat.st_uid);
	p->fl->gr_name[i] = r_grname(p_stat.st_gid);
	p->fl->size[i] = ft_itoa_ull(p_stat.st_size);
	p->fl->d_time[i] = r_dtime(p_stat.st_mtimespec.tv_sec, p);
	p->fl->m_time[i] = r_mtime(p_stat.st_mtimespec.tv_sec, p);
	p->fl->yh_time[i] = r_yhtime(p_stat.st_mtimespec.tv_sec, p, time(NULL));
	p->fl->rdev[i] = p_stat.st_rdev;
	check_fl_ints(p, i);
	r_link(p, p_stat, name, i);
	block = p_stat.st_blocks;
	return (block);
}

void			print_dir_l(char **arr_names, t_ls *p, int f)
{
	int			i;
	blkcnt_t	blocks;
	blkcnt_t	blocks_tmp;
	char		*tmp;

	i = 0;
	blocks = 0;
	while (arr_names[i])
	{
		tmp = pathname(p->path, arr_names[i]);
		if (f == 0)
			blocks_tmp = record_data(tmp, p, i);
		if (blocks_tmp == -1)
			return ;
		blocks += blocks_tmp;
		if (p->flag_a == 0 && arr_names[i][0] == '.')
			blocks -= blocks_tmp;
		free(tmp);
		i++;
	}
	if (f == 0)
		ft_printf("total %u\n", blocks);
	fl_print(p, arr_names);
}

void			print_files_l(t_ls *p)
{
	char	**arr_names;
	int		i;

	p->fl = create_fl(p->file_cnt);
	arr_names = file_names(p->targets, p->file_cnt);
	i = 0;
	while (arr_names[i])
	{
		record_data(arr_names[i], p, i);
		i++;
	}
	print_dir_l(arr_names, p, 1);
	free_dchar(arr_names, i);
	help_fl_free(p, i);
}
