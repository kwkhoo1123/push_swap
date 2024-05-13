/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:40:14 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 13:15:27 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_i(t_stk *stk)
{
	int		max;
	t_stk	*tmp;

	max = 0;
	tmp = NULL;
	if (stk)
	{
		max = stk->i;
		tmp = stk;
		while (stk)
		{
			if (stk->i >= max)
				max = stk->i;
			stk = stk->nxt;
		}
		stk = tmp;
	}
	return (max);
}

int	get_max_power(t_stk *stk, t_var *ps)
{
	int		max;
	t_stk	*tmp;

	max = 0;
	tmp = NULL;
	if (stk)
	{
		tmp = stk;
		while (stk)
		{
			if (stk->g >= max && !ashould_move(stk, ps))
				max = stk->g;
			stk = stk->nxt;
		}
		stk = tmp;
	}
	return (max);
}

int	get_min_power(t_stk *stk, t_var *ps)
{
	int	min;

	min = stk->g;
	while (stk)
	{
		if (stk->g < min && !ashould_move(stk, ps))
			min = stk->g;
		stk = stk->nxt;
	}
	return (min);
}

int	group_size_a(t_stk *stk, int group, t_var *ps)
{
	int	cnt;

	cnt = 0;
	while (stk)
	{
		if (stk->g == group && !ashould_move(stk, ps))
			cnt++;
		stk = stk->nxt;
	}
	return (cnt);
}

int	group_size_b(t_stk *stk, int group)
{
	int	cnt;

	cnt = 0;
	while (stk)
	{
		if (stk->g == group)
			cnt++;
		stk = stk->nxt;
	}
	return (cnt);
}
