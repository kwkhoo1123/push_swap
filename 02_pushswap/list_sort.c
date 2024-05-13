/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:54:21 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/15 15:34:23 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstidx(t_stk **stk, int num)
{
	t_stk	*tmp;
	int		i;

	i = 1;
	tmp = *stk;
	while (tmp != NULL)
	{
		if (tmp->num == num)
			return (i);
		i++;
		tmp = tmp->nxt;
	}
	return (0);
}

int	ft_lstnbr(t_stk **stk, int idx)
{
	t_stk	*tmp;
	int		i;

	i = 0;
	tmp = *stk;
	while (tmp != NULL)
	{
		if (i == idx)
			return (tmp->num);
		i++;
		tmp = tmp->nxt;
	}
	return (0);
}

void	ft_lstswp(t_stk *x, t_stk *y)
{
	int	tmp;

	tmp = x->num;
	x->num = y->num;
	y->num = tmp;
}

t_stk	*ft_lstsort(t_stk *stk)
{
	t_stk	*base;
	t_stk	*tmp;
	t_stk	*cmp;

	base = NULL;
	base = stk;
	tmp = NULL;
	cmp = NULL;
	while (base->nxt)
	{
		cmp = base;
		tmp = base->nxt;
		while (tmp)
		{
			if (cmp->num > tmp->num)
				cmp = tmp;
			tmp = tmp->nxt;
		}
		ft_lstswp(base, cmp);
		base = base->nxt;
	}
	return (stk);
}

void	ft_set_idx(t_stk *stk)
{
	t_stk	*tmp;
	t_stk	*tmp2;

	tmp = NULL;
	tmp = ft_lst_dup(stk);
	tmp = ft_lstsort(tmp);
	tmp2 = NULL;
	tmp2 = stk;
	while (tmp2)
	{
		tmp2->i = ft_lstidx(&tmp, tmp2->num);
		tmp2 = tmp2->nxt;
	}
	free_stk(&tmp);
}
