/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:04:09 by yjung             #+#    #+#             */
/*   Updated: 2021/07/16 15:58:06 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_num_of_eat(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->num_of_philo)
	{
		if (philo->info->philos[i].num_of_eat != philo->info->must_eat)
			return (0);
	}
	print_msg(philo, NULL, FULL);
	philo->info->finish = FULL;
	return (1);
}

void	*check_routine(void *argv)
{
	t_philo			*philo;

	philo = argv;
	while (!philo->info->finish)
	{
		pthread_mutex_lock(&philo->check_mutex);
		if ((get_time() - philo->last_time_to_eat) >= \
		philo->info->time_to_die)
		{
			print_msg(philo, "died", 0);
			pthread_mutex_unlock(&philo->check_mutex);
			philo->info->finish = DIED;
			return (NULL);
		}
		pthread_mutex_unlock(&philo->check_mutex);
		usleep(50);
	}
	return (NULL);
}
