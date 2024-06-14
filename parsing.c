/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:19:26 by umosse            #+#    #+#             */
/*   Updated: 2024/06/14 12:11:04 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parsing(t_data *data, int argc, char **argv)
{
	int	i;
	
	i = 1;
	while (i <= argc - 1)
	{
		if (ft_atol(argv[i]) == -1)
			return (-1);
		i++;
	}
	data->nphilo = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	if (argc == 6)
		data->toteat = ft_atoi(argv[5]);
	if (data->nphilo <= 0 || data->ttd <= 0 || data->tte <= 0 || data->tts <= 0 || data->toteat < 0)
		return (-1);
	return (1);
}
