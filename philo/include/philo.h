/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:14:45 by yjung             #+#    #+#             */
/*   Updated: 2021/07/02 20:59:22 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# include "philo_type.h"
// add_info.c
int			add_info(t_info **info, char *av[]);
// exit_free.c
int			free_split(char ***str);
// util.c
int			ft_isdigit(int c);
long long	ft_atoi(const char *nptr);
long long	ms_time(struct timeval time);
void		print_msg(t_philo *philo, char *str);
// routine.c
void		*start_routine(void *argv);
// init_philo.c
int			init_philo(t_info *info);
void		*check_routine(void *argv);
void		*check_must_eat(void *argv);

#endif
