/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_print_dir_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:07:06 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:07:08 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	help_hpdd(t_ls *p, int i, char *target, char **arr_names)
{
	if (p->flag_t == 1)
		p->path = target;
	choose_flash(arr_names, 0, i, p);
	p->path = NULL;
}

int		check_prf(char *name, char *path)
{
	int			i;
	struct stat	s;
	char		*tmp;

	tmp = pathname(path, name);
	i = lstat(tmp, &s);
	free(tmp);
	return (i);
}

char	**create_arrnames(int size_arr)
{
	char	**arr_names;

	if (size_arr < 1)
		return (NULL);
	else
		arr_names = malloc(sizeof(char*) * size_arr + 1);
	arr_names[size_arr] = NULL;
	return (arr_names);
}
