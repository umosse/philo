/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:38:22 by umosse            #+#    #+#             */
/*   Updated: 2024/05/30 14:03:58 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_makephilo()
{
	
}

int	philosophers()
{
	
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	if (argc >= 5 && argc <= 6)
	{
		data.nphilo = ft_atoi(argv[1]);
		data.ttd = ft_atoi(argv[2]);
		data.tte = ft_atoi(argv[3]);
		data.tts = ft_atoi(argv[4]);
		if (argc == 6)
			data.toteat = ft_atoi(argv[5]);
		ft_makephilo();
	}
}
