/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:07:01 by yjung             #+#    #+#             */
/*   Updated: 2021/07/16 17:57:49 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_info *info)
{
	pthread_t	thread;
	int			i;

	i = -1;
	info->time = get_time();
	while (++i < info->num_of_philo)
	{
		info->philos[i].last_time_to_eat = get_time();
		if (pthread_create(&thread, NULL, start_routine, &info->philos[i]) != 0)
			return (FAIL);
		pthread_detach(thread);
		if (pthread_create(&info->philos[i].thread, NULL, \
			check_routine, &info->philos[i]) != 0)
			return (FAIL);
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_join(info->philos[i].thread, NULL))
			return (FAIL);
	}
	return (SUCCESS);
}
