/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:14:45 by yjung             #+#    #+#             */
/*   Updated: 2021/07/02 18:00:53 by yjung            ###   ########.fr       */
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

#endif
