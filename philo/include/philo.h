/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:14:45 by yjung             #+#    #+#             */
/*   Updated: 2021/07/07 20:56:02 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# include "philo_type.h"
// add_info.c
int			add_info(t_info *info, int ac, char *av[]);
// util.c
long long	ft_atoi(const char *nptr);
void		print_msg(t_philo *philo, char *str);
// time.c
long long	ms_time(struct timeval time);
void		ft_usleep(int num);
// set_philo.c
int			init_philo(t_info *info);
// start_routine.c
void		*start_routine(void *argv);
// check_routine.c
void		*check_routine(void *argv);
void		*check_must_eat(void *argv);
// end_philo.c
void		end_philo(t_info *info);

#endif
