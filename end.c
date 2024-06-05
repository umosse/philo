/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:56:12 by umosse            #+#    #+#             */
/*   Updated: 2024/06/05 15:39:55 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_end(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nphilo)
	{
		i++;
	}
}

int	ft_error(char *str, t_data *data)
{
	ft_putstr_fd(str, 2);
	write (2, "\n", 1);
	if (data)
		ft_exit(data);
	return (1);
}
