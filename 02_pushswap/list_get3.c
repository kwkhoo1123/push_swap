/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:14:55 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 13:14:56 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_med(t_stk **a, t_var *ps)
{
	double	min;
	double	max;
	double	med;

	min = get_min(*a);
	max = highest_unsortable(*a, ps);
	med = ft_abs((max + min) / 2);
	return (med);
}

int	get_med_b(t_stk **a, t_var *ps)
{
	t_stk	*tmp;
	double	min;
	double	max;
	double	med;

	tmp = *a;
	min = 0;
	max = 0;
	while (tmp)
	{
		if (tmp->i < min && tmp->g == get_min_power(*a, ps))
			min = tmp->i;
		if (tmp->i > max && tmp->g == get_min_power(*a, ps))
			min = tmp->i;
		tmp = tmp->nxt;
	}
	med = ft_abs((max + min) / 2);
	return (med);
}

int	get_min_g(t_stk *stk, int group)
{
	int	min;

	min = MAX_INT;
	while (stk)
	{
		if (stk->i < min && stk->g == group)
			min = stk->i;
		stk = stk->nxt;
	}
	return (min);
}
