/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:38:44 by umosse            #+#    #+#             */
/*   Updated: 2024/06/05 15:55:14 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				eatcount;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	int				lastmeal;
}	t_philo;

typedef struct s_data
{
	int				nphilo;
	int				ttd;
	int				tte;
	int				tts;
	int				toteat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printmutex;
}	t_data;

int				ft_atoi(const char *str);
void			ft_putstr_fd(char *s, int fd);
unsigned long	ft_get_time(void);
int				ft_strlen(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_error(char *str, t_data *data);
void			ft_end(t_data *data);

#endif