/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_main_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:10:11 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:10:14 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	help_hrt(char **targets, char **argv, int j, t_ls *p)
{
	int i;
	int j_tmp;

	i = 1;
	j_tmp = j;
	while (argv[i])
	{
		if (whatisit(argv[i]) == 1)
		{
			targets[j] = ft_strdup(argv[i]);
			j++;
		}
		i++;
	}
	if (j > 1 && j_tmp != j)
		choose_flash(targets, j_tmp, j, p);
}

void	help_rt(char **targets, char **argv, t_ls *p)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (whatisit(argv[i]) > 1)
		{
			p->file_cnt++;
			targets[j] = ft_strdup(argv[i]);
			j++;
		}
		i++;
	}
	choose_flash(targets, 0, j, p);
	help_hrt(targets, argv, j, p);
}

char	**help_rt_null(void)
{
	char	**targets;

	targets = malloc(sizeof(char*) + 1);
	targets[1] = NULL;
	targets[0] = ft_strdup(".");
	return (targets);
}
