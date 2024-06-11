/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:46:46 by umosse            #+#    #+#             */
/*   Updated: 2024/06/07 17:51:55 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (SIZE_MAX / nmemb < size)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	memset(ptr, '\0', nmemb * size);
	return (ptr);
}

unsigned long	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (ft_error("Error with gettimeofday\n", NULL));
	return ((tv.tv_sec * (unsigned long)1000) + (tv.tv_usec / 1000));
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write(fd, s, ft_strlen(s));
		i++;
	}
}
