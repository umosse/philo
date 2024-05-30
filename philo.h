/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:38:44 by umosse            #+#    #+#             */
/*   Updated: 2024/05/30 14:04:55 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <unistd.h>

int	ft_atoi(const char *str);

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				eatcount;
	
}	t_philo;

typedef struct s_data
{
	int		nphilo;
	int		ttd;
	int		tte;
	int		tts;
	int		toteat;
}	t_data;

#endif