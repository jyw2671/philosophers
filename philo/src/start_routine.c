/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:06:17 by yjung             #+#    #+#             */
/*   Updated: 2021/07/16 18:08:31 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	taken_a_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->forks[philo->right]));
	print_msg(philo, "has taken a fork", 0);
	pthread_mutex_lock(&(philo->info->forks[philo->left]));
	print_msg(philo, "has taken a fork", 0);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_mutex);
	print_msg(philo, "is eating", 0);
	philo->last_time_to_eat = get_time();
	while (get_time() - philo->last_time_to_eat <= philo->info->time_to_eat \
	&& !philo->info->finish)
		usleep(1000);
	philo->num_of_eat += 1;
	if (philo->num_of_eat == philo->info->must_eat)
		philo->info->num_of_finish_philo += 1;
	pthread_mutex_unlock(&philo->check_mutex);
	put_down_fork(philo);
}

static void	sleeping(t_philo *philo)
{
	long long	curr_time;

	print_msg(philo, "is sleeping", 0);
	curr_time = get_time();
	while (get_time() - curr_time <= philo->info->time_to_sleep \
	&& !philo->info->finish)
		usleep(1000);
}

static void	thinking(t_philo *philo)
{
	print_msg(philo, "is thinking", 0);
}

void	*start_routine(void *argv)
{
	t_philo	*philo;

	philo = argv;
	if (philo->n % 2 == 1)
		ft_usleep(philo->info->time_to_eat);
	while (!philo->info->finish)
	{
		taken_a_fork(philo);
		eating(philo);
		if (philo->info->must_eat > 0 && check_num_of_eat(philo))
			break ;
		if (philo->info->finish)
			break ;
		sleeping(philo);
		if (philo->info->finish)
			break ;
		thinking(philo);
		if (philo->info->finish)
			break ;
	}
	return (NULL);
}
