/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:07:28 by umosse            #+#    #+#             */
/*   Updated: 2024/06/06 17:20:51 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(useconds_t time)
{
	unsigned long	start;
	start = ft_get_time();
	while ((ft_get_time() - start) < time)
	{
		if (usleep(time/10) == -1)
			return (-1);
	}
	return (0);
}
