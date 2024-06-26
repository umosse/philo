/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:14:01 by umosse            #+#    #+#             */
/*   Updated: 2024/06/26 15:32:51 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_onephilo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	printf("%lu philo %d has taken a fork\n",
		ft_get_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	ft_usleep(philo->data->ttd);
	return (NULL);
}

int	ft_deathcheck(t_data *data, t_philo **philos)
{
	int				i;
	unsigned long	time;

	i = 0;
	while (i < data->nphilo)
	{
		pthread_mutex_lock(&data->lock);
		time = ft_get_time();
		if (time - philos[i]->lastmeal >= data->ttd)
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
		usleep(500);
		i = 0;
		ft_deathcheck(data, philos);
		pthread_mutex_lock(&data->lock);
		if (philos[data->nphilo - 1]->eatcount >= data->toteat && argc == 6)
		{
			pthread_mutex_unlock(&data->lock);
			break ;
		}
		pthread_mutex_unlock(&data->lock);
		while (i < data->nphilo)
		{
			if (philos[i]->isdead == 1)
			{
				pthread_mutex_lock(&data->lock);
				printf("%lu philo %d died\n",
					ft_get_time() - data->start, philos[i]->id);
				pthread_mutex_unlock(&data->lock);
				return ;
			}
			i++;
		}
		usleep(500);
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
