/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:07:33 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:07:35 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_flags(t_ls *p)
{
	p->flag_l = 0;
	p->flag_t = 0;
	p->flag_r = 0;
	p->flag_a = 0;
	p->flag_rr = 0;
}

t_ls	*init_tls(void)
{
	t_ls	*p;

	if (!(p = malloc(sizeof(t_ls))))
	{
		ft_printf("init_tls: struct memory not allocated\n");
		exit(0);
	}
	init_flags(p);
	p->need_print_pathname = 0;
	p->file_cnt = 0;
	return (p);
}
