/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:38:22 by umosse            #+#    #+#             */
/*   Updated: 2024/06/05 16:02:06 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**ft_makephilo(t_data *data)
{
	int	i;
	t_philo	**philos;
	
	i = 0;
	philos = ft_calloc(data->nphilo, sizeof(t_philo *));
	while (i < data->nphilo)
	{
		philos[i] = ft_calloc(1, sizeof(t_philo));
		philos[i]->data = data;
		philos[i]->lastmeal = ft_get_time();
		philos[i]->id = i + 1;
		i++;
	}
	return (philos);
}

void	ft_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = ft_calloc(data->nphilo, sizeof(pthread_mutex_t));
	while (i < data->nphilo)
	{
		
	}
}

int	philosophers()
{
	
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	**philos;

	data = (t_data){0};
	if (argc >= 5 && argc <= 6)
	{
		data.nphilo = ft_atoi(argv[1]);
		data.ttd = ft_atoi(argv[2]);
		data.tte = ft_atoi(argv[3]);
		data.tts = ft_atoi(argv[4]);
		if (argc == 6)
			data.toteat = ft_atoi(argv[5]);
		philos = ft_makephilo(&data);
	}
}
