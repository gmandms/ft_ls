/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:12:25 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/26 14:12:47 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H
# include "FT_PRINTF/ft_printf.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct	s_flagl
{
	char	*type;
	char	**priotity;
	char	**n_link;
	int		w_n_link;
	char	**usr_name;
	int		w_usr_name;
	char	**gr_name;
	int		w_gr_name;
	char	**size;
	int		w_size;
	char	**d_time;
	char	**m_time;
	char	**yh_time;
	int		w_dtime;
	int		w_mtime;
	int		w_yhtime;
	char	**link;
	int		*rdev;
	int		w_major;
	int		w_minor;
}				t_flagl;

typedef struct	s_ls
{
	int		flag_l;
	int		flag_r;
	int		flag_a;
	int		flag_rr;
	int		flag_t;
	int		need_print_pathname;
	char	**targets;
	int		file_cnt;
	char	*path;
	t_flagl *fl;
}				t_ls;

void			ft_ls(t_ls *p, char **targets);
t_ls			*init_tls();
int				check_flags(char **argv, t_ls *p);
char			**rec_targets(char **argv, t_ls *p);
char			**help_rt_null();
int				rec_flags(t_ls *p, char *argv);
void			help_rt(char **targets, char **argv, t_ls *p);
int				whatisit(char *name);
char			*pathname(char *path, char *name);
void			help_print_dir(t_ls *p, char *target, int size_arr, int size_r);
char			**create_arrnames(int size_arr);
int				check_prf(char *name, char *path);
void			help_hpdd(t_ls *p, int i, char *target, char **arr_names);
void			flash(char **arr_names, int i, int size);
void			ft_swap_pchar(char **arr_names, int i, int i_tmp);
void			choose_flash(char **arr_names, int i, int size, t_ls *p);
void			reverse(char **arr_names, int i, int t, int size);
void			sort_time(char **arr_names, int i, int size, t_ls *p);
void			print_files_l(t_ls *p);
void			print_dir_l(char **arr_names, t_ls *p, int f);
t_flagl			*create_fl(int size);
char			r_type(char *name);
char			*r_priority(struct stat p_stat);
char			*r_usrname(uid_t uid);
char			*r_grname(gid_t gid);
char			*r_dtime(time_t filetime, t_ls *p);
char			*r_mtime(time_t filetime, t_ls *p);
char			*r_yhtime(time_t filetime, t_ls *p, time_t td);
char			*space(int size);
void			init_fl_ints(t_flagl *fl);
void			r_link(t_ls *p, struct stat p_stat, char *name, int i);
void			check_fl_ints(t_ls *p, int i);
void			fl_print(t_ls *p, char **arr_names);
void			free_dchar(char **arr_names, int size);
void			help_fl_free(t_ls *p, int size);

#endif
