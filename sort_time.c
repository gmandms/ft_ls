/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:08:04 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:08:05 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		while_start(long *arr_time, int i_tmp, int size_time)
{
	int	j;

	j = i_tmp + 1;
	while (j < size_time)
	{
		if (arr_time[j] > arr_time[i_tmp])
			i_tmp = j;
		j++;
	}
	return (i_tmp);
}

void	sort_arrtime(char **arr_names, long *arr_time, int s_n, int size_time)
{
	int		i;
	int		i_tmp;
	long	tmp;

	i = 0;
	while (i < s_n)
	{
		i_tmp = while_start(arr_time, i, size_time);
		if (i != i_tmp)
		{
			ft_swap_pchar(arr_names, i, i_tmp);
			tmp = arr_time[i];
			arr_time[i] = arr_time[i_tmp];
			arr_time[i_tmp] = tmp;
		}
		i++;
	}
}

void	sort_time(char **arr_names, int i, int size, t_ls *p)
{
	struct stat	p_stat;
	long		*arr_time;
	int			j;
	char		*tmp;
	int			i_tmp;

	arr_time = malloc(sizeof(long) * (size - i));
	j = 0;
	i_tmp = i;
	while (i < size)
	{
		tmp = pathname(p->path, arr_names[i]);
		if (lstat(tmp, &p_stat) == -1)
			perror("sort time");
		free(tmp);
		arr_time[j] = p_stat.st_mtimespec.tv_sec;
		j++;
		i++;
	}
	sort_arrtime(arr_names + i_tmp, arr_time, size - i_tmp, j);
	free(arr_time);
}
