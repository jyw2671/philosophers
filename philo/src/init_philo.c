/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:07:01 by yjung             #+#    #+#             */
/*   Updated: 2021/07/02 20:59:05 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_must_eat(void *argv)
{
	t_info	*info;

	info = argv;
	while (!info->finish)
	{
		pthread_mutex_lock(&info->finish_mutex);
		if (info->num_of_finish_philo == info->num_of_philo)
			info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
	}
	return (NULL);
}

void	*check_routine(void *argv)
{
	t_philo			*philo;
	struct timeval	curr_time;
	long long		ms;

	philo = argv;
	while (!philo->info->finish)
	{
		pthread_mutex_lock(&philo->check_mutex);
		pthread_mutex_lock(&philo->info->finish_mutex);
		gettimeofday(&curr_time, NULL);
		ms = ms_time(curr_time) - ms_time(philo->last_time_to_eat);
		gettimeofday(&curr_time, NULL);
		if (ms >= philo->info->time_to_die && philo->info->finish == 0)
		{
			printf("%lld\t%d\t %s\n", ms_time(curr_time) \
			- ms_time(philo->info->time), philo->n + 1, "died");
			philo->info->finish = 1;
		}
		pthread_mutex_unlock(&philo->info->finish_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
	}
	return (NULL);
}

int	init_philo(t_info *info)
{
	pthread_t	thread;
	int			i;

	gettimeofday(&info->time, NULL);
	while (++i < info->num_of_philo)
	{
		info->philos[i].last_time_to_eat = info->time;
		if (pthread_create(&info->philos[i].thread, NULL, \
			start_routine, &info->philos[i]))
			return (FAIL);
		if (pthread_create(&thread, NULL, check_routine, &info->philos[i]))
			return (FAIL);
		pthread_detach(thread);
	}
	if (info->must_eat != 0)
	{
		pthread_create(&thread, NULL, check_must_eat, info);
		pthread_detach(thread);
	}
	return (SUCCESS);
}
