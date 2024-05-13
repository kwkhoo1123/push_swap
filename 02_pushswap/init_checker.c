/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:43:21 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 12:54:13 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stk **stk)
{
	t_stk	*tmp;

	if (!stk)
		return (0);
	tmp = *stk;
	while (tmp && tmp->nxt)
	{
		if ((tmp)->nxt != NULL && ((tmp)->num < (tmp)->nxt->num))
			(tmp) = tmp->nxt;
		else
			return (0);
	}
	return (1);
}

void	check_dup(char **av, t_var *ps)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	while (av[i])
	{
		dup = ft_strdup(av[i]);
		j = 0;
		while (av[j])
		{
			if (j == i)
				j++;
			else if (ft_strcmp(dup, av[j]) == 0)
			{
				free(dup);
				ft_exit_ps("Error\n", 1, ps);
			}
			else
				j++;
		}
		free(dup);
		i++;
	}
}

int	check_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_overflow(char *arg)
{
	long	i;

	i = ft_atoi_long(arg);
	if (check_isdigit(arg))
		if (i >= MIN_INT && i <= MAX_INT && ft_strlen(arg) < 12)
			return (1);
	return (0);
}

int	check_numbers(char **av, t_var *ps)
{
	int		i;
	int		j;

	i = -1;
	if (!av[0])
		ft_exit_ps("Error\n", 1, ps);
	while (av[++i])
	{
		j = -1;
		if (check_overflow(av[i]) == 0)
			ft_exit_ps("Error\n", 1, ps);
	}
	return (1);
}
