/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:38:44 by umosse            #+#    #+#             */
/*   Updated: 2024/06/21 11:26:33 by umosse           ###   ########.fr       */
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
# include <limits.h>

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
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	int				toteat;
	unsigned long	start;
	int				stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
}	t_data;

//utils.c
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
unsigned long	ft_get_time(void);
void			ft_putstr_fd(char *s, int fd);
//utils2.c
int				ft_usleep(useconds_t time);
int				ft_atol(char *str);
void			ft_fork1(t_philo *philo);
void			ft_fork2(t_philo *philo);
//philo.c
void			ft_forklock(int lock, t_philo *philo);
void			ft_eatsleep(t_philo *philo);
void			*ft_routine(t_philo *philo);
int				ft_makethread(t_data *data, t_philo **philos, void *ft_routine);
//loop.c
void			ft_loop(int argc, t_data *data, t_philo **philos);
void			ft_jointhread(t_philo **philos);
//end.c
void			ft_end(t_data *data, t_philo **philos);
int				ft_error(char *str, t_data *data, t_philo **philos);
//data.c
t_philo			**ft_makephilo(t_data *data);
void			ft_forks(t_data *data);
void			ft_assignfork(t_data *data, t_philo **philos);
//parsing.c
int				ft_parsing(t_data *data, int argc, char **argv);

#endif