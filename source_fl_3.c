/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_fl_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:08:47 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:08:49 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*r_yhtime(time_t filetime, t_ls *p, time_t td)
{
	char	*str;
	char	**arr_time;
	char	*tmp;

	str = ctime(&filetime);
	arr_time = ft_strsplit(str, ' ');
	if (td - (6l * 30 * 24 * 60 * 60) < filetime)
	{
		tmp = ft_strnew(5);
		tmp = ft_strncpy(tmp, arr_time[3], 5);
	}
	else
	{
		tmp = ft_strnew(4);
		tmp = ft_strncpy(tmp, arr_time[4], 4);
	}
	str = ft_strdup(tmp);
	free(tmp);
	if (ft_strlen(str) > p->fl->w_yhtime)
		p->fl->w_yhtime = ft_strlen(str);
	free_dchar(arr_time, 5);
	return (str);
}

char	*r_mtime(time_t filetime, t_ls *p)
{
	char	*str;
	char	**arr_time;

	arr_time = ft_strsplit(ctime(&filetime), ' ');
	str = ft_strdup(arr_time[1]);
	if (ft_strlen(str) > p->fl->w_mtime)
		p->fl->w_mtime = ft_strlen(str);
	free_dchar(arr_time, 5);
	return (str);
}

char	*r_dtime(time_t filetime, t_ls *p)
{
	char	*str;
	char	**arr_time;

	arr_time = ft_strsplit(ctime(&filetime), ' ');
	str = ft_strdup(arr_time[2]);
	if (ft_strlen(str) > p->fl->w_dtime)
		p->fl->w_dtime = ft_strlen(str);
	free_dchar(arr_time, 5);
	return (str);
}
