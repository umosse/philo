/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:38:44 by umosse            #+#    #+#             */
/*   Updated: 2024/06/12 16:59:06 by umosse           ###   ########.fr       */
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
# include <stdio.h>

//Structures
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
	unsigned long				start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printmutex;
	pthread_mutex_t	is_dead_lock;
	pthread_mutex_t	is_eating_lock;
}	t_data;

//utils.c
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
unsigned long	ft_get_time(void);
void			ft_putstr_fd(char *s, int fd);
//utils2.c
int				ft_usleep(useconds_t time);
//philo.c
void			ft_forklock(int lock, t_philo *philo);
void			ft_eatsleep(t_philo *philo);
void			*ft_routine(t_philo *philo);
int				ft_makethread(t_data *data, t_philo **philos, void *ft_routine);
//end.c
void			ft_end(t_data *data, t_philo **philos);
int				ft_error(char *str, t_data *data, t_philo **philos);
//data.c
t_philo			**ft_makephilo(t_data *data);
void			ft_forks(t_data *data);
void			ft_assignfork(t_data *data, t_philo **philos);
//parsing.c

#endif