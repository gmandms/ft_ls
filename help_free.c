/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:06:43 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:07:23 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	help_fl_free(t_ls *p, int size)
{
	free(p->fl->type);
	free_dchar(p->fl->priotity, size);
	free_dchar(p->fl->n_link, size);
	free_dchar(p->fl->usr_name, size);
	free_dchar(p->fl->gr_name, size);
	free_dchar(p->fl->size, size);
	free_dchar(p->fl->d_time, size);
	free_dchar(p->fl->m_time, size);
	free_dchar(p->fl->yh_time, size);
	free_dchar(p->fl->link, size);
	free(p->fl->rdev);
	free(p->fl);
}

void	free_dchar(char **arr_names, int size)
{
	int	i;

	i = 0;
	while (i < size && arr_names[i])
	{
		free(arr_names[i]);
		i++;
	}
	free(arr_names);
}
