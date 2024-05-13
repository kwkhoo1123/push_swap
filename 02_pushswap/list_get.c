/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:06:58 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 04:47:49 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_idx(t_stk *stk, int num)
{
	int	i;

	i = 1;
	while (stk)
	{
		if (stk->num == num)
			return (i);
		stk = stk->nxt;
		i++;
	}
	return (-1);
}

int	get_pivot(t_stk *stk, float dvd)
{
	t_stk	*tmp;
	int		len;
	int		pvt;
	int		pvt_num;

	tmp = NULL;
	len = list_size(stk);
	tmp = ft_lst_dup(stk);
	tmp = ft_lstsort(tmp);
	pvt = ft_abs((float)len / dvd);
	pvt_num = ft_lstnbr(&tmp, pvt);
	free_stk(&tmp);
	return (pvt_num);
}

int	get_max2(t_stk *stk, int cap)
{
	int		max;
	t_stk	*tmp;

	max = 0;
	tmp = NULL;
	if (stk)
	{
		max = stk->num;
		tmp = stk;
		while (stk)
		{
			if (stk->num >= max && stk->num < cap)
				max = stk->num;
			stk = stk->nxt;
		}
		stk = tmp;
	}
	return (max);
}

int	get_max(t_stk *stk)
{
	int		max;
	t_stk	*tmp;

	max = 0;
	tmp = NULL;
	if (stk)
	{
		max = stk->num;
		tmp = stk;
		while (stk)
		{
			if (stk->num >= max)
				max = stk->num;
			stk = stk->nxt;
		}
		stk = tmp;
	}
	return (max);
}

int	get_min(t_stk *stk)
{
	int	min;

	min = stk->i;
	while (stk)
	{
		if (stk->i < min)
			min = stk->i;
		stk = stk->nxt;
	}
	return (min);
}
