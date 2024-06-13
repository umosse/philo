/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:19:26 by umosse            #+#    #+#             */
/*   Updated: 2024/06/12 16:19:27 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parsing(t_data *data, int argc, char **argv)
{
	data->nphilo = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	if (argc == 6)
		data->toteat = ft_atoi(argv[5]);
	if (data->nphilo < 0 || data->ttd < 0 || data->tte < 0 || data->tts < 0 || data->toteat < 0)
		return (-1);
	return (0);
}
