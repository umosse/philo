/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:38:44 by umosse            #+#    #+#             */
/*   Updated: 2024/06/06 17:48:57 by umosse           ###   ########.fr       */
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
	pthread_t		tid;
	int				id;
	int				eatcount;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	unsigned long	lastmeal;
	int				isdead;
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
	pthread_mutex_t	is_dead_lock;
}	t_data;

int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_putstr_fd(char *s, int fd);
unsigned long	ft_get_time(void);
int				ft_error(char *str, t_data *data);
t_philo			**ft_makephilo(t_data *data);
void			ft_forks(t_data *data);
void				ft_assignfork(t_data *data, t_philo **philos);
void			ft_end(t_data *data);
int				ft_error(char *str, t_data *data);
int				ft_usleep(useconds_t time);

#endif