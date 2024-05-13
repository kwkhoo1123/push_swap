/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:31:42 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:48 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_power(double size)
{
	double	tmp;
	int		i;

	i = 1;
	tmp = size;
	while (tmp >= 4)
	{
		tmp = ft_abs(tmp / 2);
		if (tmp <= 3)
			return (i);
		i++;
	}
	return (i);
}

int	ashould_move(t_stk *stk, t_var *ps)
{
	t_stk	*tmp;

	tmp = NULL;
	tmp = stk;
	while (tmp)
	{
		if (tmp->i == ps->len)
			return (1);
		else
		{
			if (tmp->nxt == NULL)
				return (0);
			else if (tmp->i + 1 == tmp->nxt->i)
				tmp = tmp->nxt;
			else
				return (0);
		}
	}
	return (0);
}

int	highest_unsortable(t_stk *stk, t_var *ps)
{
	t_stk	*tmp;
	int		max;

	if (!stk)
		return (0);
	tmp = NULL;
	tmp = stk;
	max = 0;
	while (tmp)
	{
		if (tmp->i >= max && !ashould_move(tmp, ps))
			max = tmp->i;
		tmp = tmp->nxt;
	}
	return (max);
}

char	**fill_args(t_var *ps, int ac, char **av)
{
	ps->fd = 1;
	if (ac == 2)
		ps->split = ft_split(av[1], ' ');
	else
		ps->split = &av[1];
	return (ps->split);
}

t_var	*ft_init_var(t_var *ps)
{
	ps = (t_var *)malloc(sizeof(t_var));
	if (ps == NULL)
		exit(1);
	ps->a_stk = NULL;
	ps->b_stk = NULL;
	ps->len = 0;
	ps->line = NULL;
	ps->split = NULL;
	ps->log = NULL;
	ps->seg = 0;
	ps->stg = 1;
	return (ps);
}
