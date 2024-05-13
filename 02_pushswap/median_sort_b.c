/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 01:24:14 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 15:29:55 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_half(t_stk **a, t_stk **b, t_var *ps)
{
	int		pvt;
	double	min;
	double	max;
	int		gsize_old;
	int		gsize_new;

	ps->stg = get_max_power(*b, ps);
	gsize_new = group_size_b(*b, ps->stg);
	gsize_old = gsize_new;
	max = get_max_i(*b);
	min = get_min_g(*b, ps->stg);
	pvt = ft_abs((max + min) / 2);
	while (gsize_new > gsize_old / 2)
	{
		gsize_new = group_size_b(*b, ps->stg);
		if ((*b)->i >= pvt)
			pick_case(a, b, PA, ps);
		else
			rot_next_b(a, b, ps, pvt);
		gsize_new = group_size_b(*b, ps->stg);
	}
}

void	below_8_b(t_stk **a, t_stk **b, t_var *ps)
{
	int		pow;

	pow = get_max_power(*b, ps);
	while (group_size_b(*b, pow) > 0)
	{
		while ((*b)->num != get_max(*b))
		{
			rot_max_b(a, b, ps, get_max(*b));
		}
		pick_case(a, b, PA, ps);
	}
}

void	b_to_a(t_stk **a, t_stk **b, t_var *ps)
{
	int	gsize;

	ps->stg = get_max_power(*b, ps);
	gsize = group_size_b(*b, ps->stg);
	if (gsize <= 16)
		below_8_b(a, b, ps);
	else if (gsize > 8)
	{
		push_back_half(a, b, ps);
	}
}
