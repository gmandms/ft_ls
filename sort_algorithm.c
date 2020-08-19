/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:07:54 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:07:56 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_pchar(char **arr_names, int i, int i_tmp)
{
	char	*tmp;

	tmp = arr_names[i];
	arr_names[i] = arr_names[i_tmp];
	arr_names[i_tmp] = tmp;
}

void	flash(char **arr_names, int i, int size)
{
	int		it;
	int		start;

	start = i;
	while (i < size - 1)
	{
		it = i + 1;
		while (it > start && ft_strcmp(arr_names[it], arr_names[it - 1]) < 0)
		{
			ft_swap_pchar(arr_names, it - 1, it);
			it--;
		}
		i++;
	}
}

void	reverse(char **arr_names, int i, int t, int size)
{
	char	**tmp;
	int		j;
	int		t2;

	j = 0;
	if ((size - i) <= 0)
		return ;
	tmp = malloc(sizeof(char*) * (size - i) + 1);
	tmp[size - i] = NULL;
	while (i < size)
	{
		tmp[j] = ft_strdup(arr_names[i]);
		i++;
		j++;
	}
	t2 = j;
	size = t;
	while (--i > size - 1)
	{
		free(arr_names[t]);
		arr_names[t] = ft_strdup(tmp[--j]);
		t++;
	}
	free_dchar(tmp, t2);
}

void	choose_flash(char **arr_names, int i, int size, t_ls *p)
{
	if (p->flag_t == 1)
		sort_time(arr_names, i, size, p);
	else
		flash(arr_names, i, size);
	if (p->flag_rr == 1 && size > 1)
		reverse(arr_names, i, i, size);
}
