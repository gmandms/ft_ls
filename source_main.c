/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:10:04 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:10:05 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		rec_flags(t_ls *p, char *argv)
{
	int i;

	i = 1;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (argv[i] == 'l')
			p->flag_l = 1;
		else if (argv[i] == 'R')
			p->flag_r = 1;
		else if (argv[i] == 'a')
			p->flag_a = 1;
		else if (argv[i] == 'r')
			p->flag_rr = 1;
		else if (argv[i] == 't')
			p->flag_t = 1;
		else
			return (-1);
		i++;
	}
	return (0);
}

int		check_flags(char **argv, t_ls *p)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' || (argv[i][0] == '-' && argv[i][1] == '-'))
		{
			if (rec_flags(p, argv[i]) == -1)
			{
				ft_printf("check flags: illegal flags, use this -tarRl\n");
				return (i);
			}
		}
		else
			return (i);
		i++;
	}
	return (i);
}

char	**help_rectarg(char **argv, int size, t_ls *p)
{
	char	**targets;

	if (!(targets = malloc(sizeof(char*) * size + 1)))
	{
		ft_printf("rec_targets: memory targets' not allocated");
		exit(0);
	}
	targets[size] = NULL;
	help_rt(targets, argv, p);
	if (size > 0)
		p->need_print_pathname = 1;
	return (targets);
}

char	**ret_targets(int size, int f, char **argv, t_ls *p)
{
	char	**targets;

	if (size == 0 && f != -1)
		targets = help_rt_null();
	else if (size > 0)
		targets = help_rectarg(argv, size, p);
	else
		return (NULL);
	return (targets);
}

char	**rec_targets(char **argv, t_ls *p)
{
	int		i;
	int		size;
	char	**targets;
	int		f;

	i = check_flags(argv, p);
	size = 0;
	f = 0;
	while (argv[i])
	{
		if (whatisit(argv[i]) > 0)
			size++;
		else
		{
			ft_printf("ls: No such file or directory - %s\n", argv[i]);
			f = -1;
		}
		i++;
	}
	targets = ret_targets(size, f, argv, p);
	return (targets);
}
