/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:07:28 by umosse            #+#    #+#             */
/*   Updated: 2024/06/26 11:02:18 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(useconds_t time)
{
	unsigned long	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
	{
		if (usleep(time / 10) == -1)
			return (-1);
	}
	return (0);
}

int	ft_atol(char *str)
{
	long	nb;
	int		sign;
	long	i;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		nb = nb * 10 + (str[i] - '0');
		if ((nb * sign) > INT_MAX)
			return (-1);
		if ((nb * sign) < INT_MIN)
			return (-1);
		i++;
	}
	return (1);
}

void	ft_fork1(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->stop == 0)
		printf("%lu philo %d has taken a fork\n",
			ft_get_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->stop == 0)
		printf("%lu philo %d has taken a fork\n",
			ft_get_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->lock);
}

void	ft_fork2(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->stop == 0)
		printf("%lu philo %d has taken a fork\n",
			ft_get_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(philo->rfork);
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->stop == 0)
		printf("%lu philo %d has taken a fork\n",
			ft_get_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->lock);
}
