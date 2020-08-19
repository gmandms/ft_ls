/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_print_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:06:56 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:06:58 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	record_r_targets(t_ls *p, int *size_r, char *target, char *name)
{
	char		*tmp;
	struct stat	s;
	int			i;

	if (p->flag_r == 1 && *size_r > -1)
	{
		tmp = pathname(target, name);
		i = lstat(tmp, &s);
		if (whatisit(tmp) == 1 && i != -1)
		{
			if (ft_strcmp(name, ".") != 0 && ft_strcmp(name, "..") != 0)
				p->targets[--*size_r] = ft_strdup(tmp);
		}
		free(tmp);
	}
}

void	print_arrnames(char **arr_names, t_ls *p)
{
	int i;

	i = 0;
	while (arr_names[i])
	{
		if (arr_names[i][0] == '.' && p->flag_a == 1)
			ft_printf("%s\n", arr_names[i++]);
		else if (p->flag_a == 0 && arr_names[i][0] == '.')
			i++;
		else
			ft_printf("%s\n", arr_names[i++]);
	}
}

void	help_hpd(t_ls *p, int size_r)
{
	if (p->flag_r == 1 && size_r > 0)
	{
		p->targets = malloc(sizeof(char *) * size_r + 1);
		p->targets[size_r] = NULL;
	}
}

void	str_hpd(t_ls *p, char **arr_names, int i, char *target)
{
	if (p->flag_l)
	{
		p->path = target;
		p->fl = create_fl(i);
		print_dir_l(arr_names, p, 0);
		help_fl_free(p, i);
	}
	else
		print_arrnames(arr_names, p);
	free_dchar(arr_names, i);
}

void	help_print_dir(t_ls *p, char *target, int size_arr, int size_r)
{
	DIR				*dir_p;
	struct dirent	*struct_p;
	char			**arr_names;
	int				i;
	int				j;

	if (!(dir_p = opendir(target)))
		return ;
	i = size_arr;
	j = size_r;
	if (!(arr_names = create_arrnames(size_arr)))
		return ;
	help_hpd(p, size_r);
	while ((struct_p = readdir(dir_p)))
	{
		if (check_prf(struct_p->d_name, target) == 0)
		{
			arr_names[--size_arr] = ft_strdup(struct_p->d_name);
			record_r_targets(p, &size_r, target, struct_p->d_name);
		}
	}
	closedir(dir_p);
	help_hpdd(p, i, target, arr_names);
	choose_flash(p->targets, 0, j, p);
	str_hpd(p, arr_names, i, target);
}
