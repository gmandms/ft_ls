/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:38:02 by ncrane            #+#    #+#             */
/*   Updated: 2020/07/16 19:38:05 by ncrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "LIBFT/libft.h"

typedef struct			s_str
{
	char	*f;
	char	*f_std;
}						t_str;

typedef struct			s_printf
{
	t_str	*p_str;
	int		ca;
	int		precision;
	int		p_true;
	int		width;
	char	c_width;
	int		minus;
	int		plus;
	int		n_sign;
	int		space;
	int		nzero;
	int		i;
	int		n_min;
}						t_printf;

int						ft_printf(char *format, ...);
char					*rec_f(char *format);
char					*rec_f_std(char *str);
int						rec_pr(char *str, t_printf *p);
void					rec_w(char *str, t_printf *p);
void					print_ap(va_list ap, t_printf *p);
void					format_c(va_list ap, t_printf *p);
void					format_s(va_list ap, t_printf *p);
void					format_p(va_list ap, t_printf *p);
void					format_i(va_list ap, t_printf *p);
void					format_d(va_list ap, t_printf *p);
void					unstd_print_lli(char *str, int w, t_printf *p);
void					format_o(va_list ap, t_printf *p);
void					format_u(va_list ap, t_printf *p);
void					format_x(va_list ap, t_printf *p);
char					*perevod_vosm(unsigned long long n);
void					ft_putnbr_ull(unsigned long long n);
char					*perevod_shes(unsigned long long n, char x);
char					*ft_itoa_ull(unsigned long long n);
void					unstd_x(va_list ap, t_printf *p, char c);
void					format_xx(va_list ap, t_printf *p);
void					format_f(va_list ap, t_printf *p);
char					*extra_ds(double n, t_printf *p);
char					*ft_itoa_lli(long long int n);
void					format_percent(t_printf *p);
char					*double_str(long double n, t_printf *p);
int						ds_size(t_printf *p);
char					*ft_pow(char *str, long double n, t_printf *p);
char					*di_pr(char *str, t_printf *p);
char					*di_create(long long int i, t_printf *p);
char					*di_source(char *str, t_printf *p);
char					*pr_rec(char *str, int size);
void					help_o_pr(int pr, int w, char *str, t_printf *p);
void					p_help(char *str, t_printf *p);
unsigned long long		ret_n(va_list ap, t_printf *p);
void					put_unstd_x(char *str, t_printf *p);
void					unstd_print_ull(char *str, int w, int pr, t_printf *p);
char					*p_pr(char *str, t_printf *p, char c);
char					*help_for_ns_w_else(char *r, char *str, char *x, int w);
char					*help_for_ns_w_if(char *r, char *str, char *x, int w);
void					help_put_unstd_x(char *str, t_printf *p, int wr);
char					*rec_x_str(unsigned long long n, t_printf *p, char ch);
char					*n_sign(char c, char *str);
int						rec_pr(char *str, t_printf *p);
void					help_free(t_printf *p);
void					help_print(t_printf *p, va_list ap);
int						help_while(char *format, int i, t_printf *p);
void					create_source(t_printf *p);
void					change_c(char *str, int i);

#endif
