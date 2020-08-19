/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_fl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:08:27 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:08:29 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*r_grname(gid_t gid)
{
	char			*str;
	struct group	*p_stat;

	p_stat = getgrgid(gid);
	str = ft_strdup(p_stat->gr_name);
	return (str);
}

char	*r_usrname(uid_t uid)
{
	char			*str;
	struct passwd	*p_stat;

	p_stat = getpwuid(uid);
	if (p_stat == NULL)
		str = ft_itoa_ull(uid);
	else
		str = ft_strdup(p_stat->pw_name);
	return (str);
}

char	*r_priority(struct stat p_stat)
{
	char	*priority;

	priority = ft_strnew(9);
	priority[0] = (S_IRUSR & p_stat.st_mode) ? 'r' : '-';
	priority[1] = (S_IWUSR & p_stat.st_mode) ? 'w' : '-';
	priority[2] = (S_IXUSR & p_stat.st_mode) ? 'x' : '-';
	priority[3] = (S_IRGRP & p_stat.st_mode) ? 'r' : '-';
	priority[4] = (S_IWGRP & p_stat.st_mode) ? 'w' : '-';
	priority[5] = (S_IXGRP & p_stat.st_mode) ? 'x' : '-';
	priority[6] = (S_IROTH & p_stat.st_mode) ? 'r' : '-';
	priority[7] = (S_IWOTH & p_stat.st_mode) ? 'w' : '-';
	priority[8] = (S_IXOTH & p_stat.st_mode) ? 'x' : '-';
	return (priority);
}

char	r_type(char *name)
{
	if (whatisit(name) == 1)
		return ('d');
	else if (whatisit(name) == 2)
		return ('-');
	else if (whatisit(name) == 3)
		return ('s');
	else if (whatisit(name) == 4)
		return ('l');
	else if (whatisit(name) == 5)
		return ('b');
	else if (whatisit(name) == 6)
		return ('c');
	else if (whatisit(name) == 7)
		return ('p');
	else
	{
		ft_printf("r_type: unexpected type");
		return ('\0');
	}
}
