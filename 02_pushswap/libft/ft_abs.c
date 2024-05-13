/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:53:51 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/15 18:52:20 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(float num)
{
	int	i_num;

	i_num = (int)num;
	if ((num - i_num) >= 0.5)
		return ((int) num + 1);
	else
		return ((int) num);
}
