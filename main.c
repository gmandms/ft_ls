/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:07:42 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:07:44 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_ls	*p;

	p = init_tls();
	p->path = 0;
	if (argc > 1)
	{
		if (!(p->targets = rec_targets(argv, p)))
		{
			free(p);
			return (0);
		}
	}
	else
		p->targets = help_rt_null();
	ft_ls(p, p->targets);
	free(p);
	return (0);
}
