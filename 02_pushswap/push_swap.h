/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:31:22 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 14:34:06 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "libft/libft.h"

# define SA		1
# define SB		2
# define PA		3
# define PB		4
# define RA		5
# define RB		6
# define RRA	7
# define RRB	8
# define SS		9
# define RR		10
# define RRR	11

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stk
{
	int				num;
	int				i;
	int				g;
	struct s_stk	*nxt;
	struct s_stk	*prv;
}	t_stk;

typedef struct s_var
{
	char			*line;
	char			**split;
	char			**av;
	char			*log;
	int				len;
	int				fd;
	double			seg;
	int				stg;
	int				pow;
	t_stk			*a_stk;
	t_stk			*b_stk;
}	t_var;

void	check_dup(char **av, t_var *ps);
int		check_numbers(char **av, t_var *ps);
int		check_sort(t_stk **stk);
t_var	*ft_init_var(t_var *ps);

void	ft_exit_ps(char *str, int err, t_var *ps);
void	free_stk(t_stk **stk);

char	**fill_args(t_var *ps, int ac, char **av);
char	*trim_log(char *str);
void	fill_list(t_var *ps, char **split, t_stk *tmp);
void	add_front(t_stk **top, t_stk *new);
void	add_back_r(t_stk **top);
void	add_back(t_stk **lst, t_stk *new);
int		list_size(t_stk *stk);
t_stk	*ft_lst_last(t_stk *a);
t_stk	*ft_lst_dup(t_stk *stk);

t_stk	*ft_lstsort(t_stk *stk);
int		ft_lstidx(t_stk **stk, int num);
int		ft_lstnbr(t_stk **stk, int idx);
void	ft_lstswp(t_stk *x, t_stk *y);
void	ft_set_idx(t_stk *stk);

int		get_idx(t_stk *stk, int num);
int		get_pivot(t_stk *stk, float dvd);
int		get_max2(t_stk *stk, int cap);
int		get_max(t_stk *stk);
int		get_min(t_stk *stk);
int		has_above(t_stk *stk, int idx);
int		has_below(t_stk *stk, int idx);
int		ashould_move(t_stk *a, t_var *ps);
int		highest_unsortable(t_stk *stk, t_var *ps);
int		find_power(double size);

int		get_max_i(t_stk *stk);
int		get_max_power(t_stk *stk, t_var *ps);
int		get_min_power(t_stk *stk, t_var *ps);
int		group_size_a(t_stk *stk, int group, t_var *ps);
int		group_size_b(t_stk *stk, int group);
int		get_med(t_stk **a, t_var *ps);
int		get_med_b(t_stk **a, t_var *ps);
int		get_min_g(t_stk *stk, int group);

void	s_stk(t_stk **top);
void	p_stk(t_stk **a, t_stk **b, t_stk *tmp);
void	rr_stk(t_stk **top, t_stk *tmp);
void	r_stk(t_stk **top);

void	next_next_case(t_stk **a, t_stk **b, int c, t_var *ps);
void	next_case(t_stk **a, t_stk **b, int c, t_var *ps);
void	pick_case(t_stk **a, t_stk **b, int c, t_var *ps);

void	rot_min_small(t_stk **a, t_stk **b, t_var *ps, int min);

void	sort_small(t_stk **a, t_stk **b, int len, t_var *ps);
void	sort_big(t_stk **a, t_stk **b, t_var *ps);

void	case_with_10(t_stk **a, t_stk **b, int len, t_var *ps);
void	case_with_3(t_stk **a, t_stk **b, t_var *ps);
void	sort_big_1(t_stk **a, t_stk **b, t_var *ps);
void	sort_big_2(t_stk **a, t_stk **b, t_var *ps);
void	sort_big_3(t_stk **a, t_stk **b, t_var *ps);

void	rot_next_a(t_stk **a, t_stk **b, t_var *ps, int pvt);
void	rot_next_b(t_stk **a, t_stk **b, t_var *ps, int pvt);

void	sort_b(t_stk **a, t_stk **b, t_var *ps);
void	push_to_a(t_stk **a, t_stk **b, t_var *ps);
void	push_to_b(t_stk **a, t_stk **b, t_var *ps);
void	ft_lst_all(t_stk *stk, t_var *ps);

void	rot_max_b(t_stk **a, t_stk **b, t_var *ps, int max);

void	check_a_top(t_stk **a, t_stk **b, t_var *ps);
void	check_b_top(t_stk **a, t_stk **b, t_var *ps);
void	init_median_sort(t_stk **a, t_stk **b, t_var *ps);
void	next_median_sort(t_stk **a, t_stk **b, t_var *ps);
void	b_to_a(t_stk **a, t_stk **b, t_var *ps);

#endif