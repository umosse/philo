/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:14:01 by umosse            #+#    #+#             */
/*   Updated: 2024/06/18 17:46:52 by umosse           ###   ########.fr       */
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
		pthread_mutex_lock(&data->lock);
		time = ft_get_time();
		if (time - philos[i]->lastmeal > data->ttd)
		{
			philos[i]->isdead = 1;
			philos[i]->data->stop = 1;
			pthread_mutex_unlock(&data->lock);
			return (1);
		}
		pthread_mutex_unlock(&data->lock);
		i++;
	}
	return (0);
}

void	ft_loop(int argc, t_data *data, t_philo **philos)
{
	int	i;

	while (1)
	{
		i = 0;
		ft_deathcheck(data, philos);
		if (philos[data->nphilo - 1]->eatcount >= data->toteat && argc == 6)
			break ;
		while (i < data->nphilo)
		{
			if (philos[i]->isdead == 1)
			{
				pthread_mutex_lock(&data->lock);
				printf("%lu philo %d died\n", ft_get_time() - data->start, philos[i]->id);
				pthread_mutex_unlock(&data->lock);
				return ;
			}
			i++;
		}
	}
}

void	ft_jointhread(t_philo **philos)
{
	int	i;

	i = 0;
	while (i < philos[0]->data->nphilo)
	{
		pthread_join(philos[i]->tid, NULL);
		i++;
	}
}
