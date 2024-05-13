/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:52:13 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 15:14:01 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*ft_lst_last(t_stk *a)
{
	t_stk	*tmp;

	tmp = a;
	while ((tmp)->nxt)
		(tmp) = (tmp)->nxt;
	return (tmp);
}

t_stk	*ft_lst_dup(t_stk *stk)
{
	t_stk	*tmp1;
	t_stk	*tmp2;

	tmp1 = malloc(sizeof(t_stk));
	ft_bzero(tmp1, sizeof(t_stk));
	tmp2 = tmp1;
	while (stk)
	{
		tmp1->num = stk->num;
		if (stk->nxt)
		{
			tmp1->nxt = malloc(sizeof(t_stk));
			ft_bzero(tmp1->nxt, sizeof(t_stk));
			tmp1 = tmp1->nxt;
		}
		stk = stk->nxt;
	}
	tmp1 = tmp2;
	return (tmp1);
}

int	has_below(t_stk *stk, int idx)
{
	t_stk	*tmp;

	tmp = NULL;
	tmp = stk;
	while (tmp)
	{
		if (tmp->i < idx)
			return (1);
		else
			tmp = tmp->nxt;
	}
	return (0);
}

int	has_above(t_stk *stk, int idx)
{
	t_stk	*tmp;

	tmp = NULL;
	tmp = stk;
	while (tmp)
	{
		if (tmp->i >= idx)
			return (1);
		else
			tmp = tmp->nxt;
	}
	return (0);
}
/* 
void	ft_lst_all(t_stk *stk, t_var *ps)
{
	t_stk	*tmp;

	if (!stk)
		return ;
	tmp = stk;
		printf("------\n");
	while (tmp)
	{
		printf("num: %d group: %d move %d\n", tmp->num, tmp->g, ashould_move(tmp, ps));
		(tmp) = tmp->nxt;
	}
		printf("------\n");
}
 */