/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:07:01 by yjung             #+#    #+#             */
/*   Updated: 2021/07/07 17:13:22 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_info *info)
{
	pthread_t	thread;
	int			i;

	i = -1;
	gettimeofday(&info->time, NULL);
	while (++i < info->num_of_philo)
	{
		info->philos[i].last_time_to_eat = info->time;
		if (pthread_create(&info->philos[i].thread, NULL, \
			start_routine, &info->philos[i]) != 0)
			return (FAIL);
		if (pthread_create(&thread, NULL, check_routine, &info->philos[i]) != 0)
			return (FAIL);
		pthread_detach(thread);
	}
	if (info->must_eat != 0)
	{
		if (pthread_create(&thread, NULL, check_must_eat, info) != 0)
			return (FAIL);
		pthread_detach(thread);
	}
	return (SUCCESS);
}
