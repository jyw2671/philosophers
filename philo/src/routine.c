/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:06:17 by yjung             #+#    #+#             */
/*   Updated: 2021/07/04 17:30:33 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	taken_a_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	print_philo_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->left);
	print_philo_msg(philo, "has taken a fork");
}

static void	eating(t_philo *philo)
{
	long long	ms;

	pthread_mutex_lock(&philo->check_mutex);
	gettimeofday(&philo->last_time_to_eat, NULL);
	ms = time_to_ms(philo->last_time_to_eat) - \
		time_to_ms(philo->info->time);
	pthread_mutex_lock(&philo->info->finish_mutex);
	if (!philo->info->finish)
		printf("%lld\t%d\t %s\n", ms, philo->n + 1, "is eating");
	philo->num_of_eat += 1;
	if (philo->num_of_eat == philo->info->must_eat)
		philo->info->num_of_finish_philo += 1;
	pthread_mutex_unlock(&philo->info->finish_mutex);
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(&philo->check_mutex);
}

static void	sleeping(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	usleep(philo->info->time_to_sleep * 1000);
}

static void	thinking(t_philo *philo)
{
	print_msg(philo, "is thinking");
}

void	*start_routine(void *argv)
{
	t_philo	*philo;

	philo = argv;
	while (!philo->info->finish)
	{
		taken_a_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}
