/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:56:12 by umosse            #+#    #+#             */
/*   Updated: 2024/06/21 11:15:53 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_freeall(t_data *data, t_philo **philos)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		free (data->forks);
		data->forks = NULL;
	}
	while (i < data->nphilo)
	{
		if (philos)
		{
			free (philos[i]);
			philos[i] = NULL;
		}
		i++;
	}
	free (philos);
}

void	ft_end(t_data *data, t_philo **philos)
{
	int	i;

	i = 0;
	while (i < data->nphilo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
	ft_freeall(data, philos);
}

int	ft_error(char *str, t_data *data, t_philo **philos)
{
	ft_putstr_fd(str, 2);
	write (2, "\n", 1);
	if (data)
		ft_end(data, philos);
	return (-1);
}
