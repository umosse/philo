/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:14:01 by umosse            #+#    #+#             */
/*   Updated: 2024/06/17 15:39:27 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_deathcheck(t_data *data, t_philo **philos)
{
	int				i;
	unsigned long	time;

	i = 0;
	while (i < data->nphilo)
	{
		pthread_mutex_lock(&data->is_dead_lock);
		time = ft_get_time();
		if (time - philos[i]->lastmeal > data->ttd)
		{
			philos[i]->isdead = 1;
			pthread_mutex_unlock(&data->is_dead_lock);
			return (1);
		}
		pthread_mutex_unlock(&data->is_dead_lock);
		i++;
	}
	return (0);
}

void	ft_loop(int argc, t_data *data, t_philo **philos)
{
	while (1)
	{
		ft_deathcheck(data, philos);
		if (philos[data->nphilo - 1]->eatcount >= data->toteat && argc == 6)
			break ;
		if (philos[data->nphilo - 1]->isdead == 1)
			break ;
	}
}
