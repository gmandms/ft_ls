/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_ft_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:09:51 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:09:53 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*pathname(char *path, char *name)
{
	char	*r_str;
	char	*tmp;

	if (!(path))
		r_str = ft_strdup(name);
	else if (ft_strcmp(path, "/") != 0)
	{
		r_str = ft_strjoin(path, "/");
		tmp = r_str;
		r_str = ft_strjoin(r_str, name);
		free(tmp);
	}
	else
		r_str = ft_strjoin(path, name);
	return (r_str);
}

int		whatisit(char *name)
{
	struct stat	wit;

	if (lstat(name, &wit) == -1)
		return (-1);
	if (S_IFDIR == (wit.st_mode & S_IFMT))
		return (1);
	if (S_IFREG == (wit.st_mode & S_IFMT))
		return (2);
	if (S_IFSOCK == (wit.st_mode & S_IFMT))
		return (3);
	if (S_IFLNK == (wit.st_mode & S_IFMT))
		return (4);
	if (S_IFBLK == (wit.st_mode & S_IFMT))
		return (5);
	if (S_IFCHR == (wit.st_mode & S_IFMT))
		return (6);
	if (S_IFCHR == (wit.st_mode & S_IFMT))
		return (7);
	return (0);
}
