/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:06:22 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:06:24 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		for_r_count(t_ls *p, char *name, char *target)
{
	char	*tmp;

	if (p->flag_r == 1)
	{
		tmp = pathname(target, name);
		if (whatisit(tmp) == 1)
		{
			if (ft_strcmp(name, ".") != 0 && ft_strcmp(name, "..") != 0)
			{
				free(tmp);
				return (1);
			}
		}
		free(tmp);
	}
	return (0);
}

int		print_dir(char *target, t_ls *p)
{
	DIR				*dir_p;
	struct dirent	*struct_p;
	int				size;
	int				arr_size;

	size = 0;
	arr_size = 0;
	if (!(dir_p = opendir(target)))
	{
		perror("print_dir");
		return (size);
	}
	while ((struct_p = readdir(dir_p)))
	{
		if (check_prf(struct_p->d_name, target) == 0)
			arr_size++;
		size += for_r_count(p, struct_p->d_name, target);
	}
	closedir(dir_p);
	if (arr_size > 0)
		help_print_dir(p, target, arr_size, size);
	return (size);
}

void	print_file(char *target)
{
	ft_printf("%s\n", target);
}

int		print_target(char *target, t_ls *p)
{
	int size;

	size = 0;
	if (whatisit(target) == 1)
		size = print_dir(target, p);
	else if (whatisit(target) > 0)
		print_file(target);
	else
		ft_printf("print_target: unexpected target\n");
	return (size);
}

void	ft_ls(t_ls *p, char **targets)
{
	int	i;
	int size;

	i = 0;
	if (p->file_cnt > 0 && p->flag_l == 1)
	{
		p->path = NULL;
		print_files_l(p);
		i += p->file_cnt;
		p->file_cnt = 0;
	}
	while (targets[i])
	{
		if (p->need_print_pathname == 1 && whatisit(targets[i]) == 1)
			ft_printf("\n%s:\n", targets[i]);
		size = print_target(targets[i], p);
		if (p->flag_r == 1 && size > 0)
		{
			p->need_print_pathname = 1;
			ft_ls(p, p->targets);
		}
		i++;
	}
	free_dchar(targets, i);
}
