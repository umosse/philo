/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:38:22 by umosse            #+#    #+#             */
/*   Updated: 2024/06/12 16:59:38 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_forklock(int lock, t_philo *philo)
{
	if (lock == 1)
	{
		if (philo->id == 1)
		{
			pthread_mutex_lock(philo->rfork);
			printf("philo %d has taken a fork\n", philo->id);
			pthread_mutex_lock(philo->lfork);
			printf("philo %d has taken a fork\n", philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->lfork);
			printf("philo %d has taken a fork\n", philo->id);
			pthread_mutex_lock(philo->rfork);
			printf("%lu philo %d has taken a fork\n", ft_get_time() - philo->data->start, philo->id);
		}
	}
	else if (lock == 0)
	{
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
	}
}

void	ft_eatsleep(t_philo *philo)
{
	ft_forklock(1, philo);
	printf("philo %d is eating\n", philo->id);
	pthread_mutex_lock(&philo->data->is_eating_lock);
	philo->lastmeal = ft_get_time();
	philo->eatcount++;
	pthread_mutex_unlock(&philo->data->is_eating_lock);
	ft_usleep(philo->data->tte);
	ft_forklock(0, philo);
	printf("philo %d is sleeping\n", philo->id);
	ft_usleep(philo->data->tts);
	//ft_usleep(1);
	printf("philo %d is thinking\n", philo->id);
}

void	*ft_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->tte / 2);
	while (1)
	{
		pthread_mutex_lock(&philo->data->is_dead_lock);
		if (philo->isdead == 1 || philo->eatcount >= philo->data->toteat)
		{
			pthread_mutex_unlock(&philo->data->is_dead_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->data->is_dead_lock);
		ft_eatsleep(philo);
	}
	return (NULL);
}

int	ft_makethread(t_data *data, t_philo **philos, void *ft_routine)
{
	int	i;

	i = 0;
	data->start = ft_get_time();
	while (i < data->nphilo)
	{
		if (pthread_create(&philos[i]->tid, NULL, ft_routine, philos[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
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
		ft_forks(&data);
		ft_assignfork(&data, philos);
		if (ft_makethread(&data, philos, ft_routine) == -1)
		{
			ft_error("Error making threads\n", &data, philos);
		}
		while (1);
	}
	return (0);
}
