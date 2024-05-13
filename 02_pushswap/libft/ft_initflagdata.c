/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initflagdata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:19:40 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/20 20:44:26 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_initflagdata(t_flagdata *data)
{
	data->hash = 0;
	data->space = 0;
	data->plus = 0;
	data->minus = 0;
	data->min = 0;
	data->zero = 0;
	data->preci = 0;
}
