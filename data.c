/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:32:32 by umosse            #+#    #+#             */
/*   Updated: 2024/06/18 17:43:57 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**ft_makephilo(t_data *data)
{
	int		i;
	t_philo	**philos;

	i = 0;
	philos = ft_calloc(data->nphilo, sizeof(t_philo *));
	if (!philos)
		return (NULL);
	while (i < data->nphilo)
	{
		philos[i] = ft_calloc(1, sizeof(t_philo));
		if (!philos[i])
			return (NULL);
		philos[i]->data = data;
		philos[i]->lastmeal = ft_get_time();
		philos[i]->id = i + 1;
		i++;
	}
	return (philos);
}

int	ft_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = ft_calloc(data->nphilo, sizeof(pthread_mutex_t));
	if (!data->forks)
		return (-1);
	while (i < data->nphilo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

void	ft_assignfork(t_data *data, t_philo **philos)
{
	int	i;

	i = 0;
	while (i < data->nphilo)
	{
		philos[i]->rfork = &data->forks[i];
		philos[i]->lfork = &data->forks[(i + data->nphilo - 1) % data->nphilo];
		i++;
	}
}
