/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:06:17 by yjung             #+#    #+#             */
/*   Updated: 2021/07/07 22:19:22 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	taken_a_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->forks[philo->right]));
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->info->forks[philo->left]));
	print_msg(philo, "has taken a fork");
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_mutex);
	print_msg(philo, "is eating");
	philo->num_of_eat += 1;
	if (philo->num_of_eat == philo->info->must_eat)
		philo->info->num_of_finish_philo += 1;
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->check_mutex);
	put_down_fork(philo);
}

static void	sleeping(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	ft_usleep(philo->info->time_to_sleep);
}

static void	thinking(t_philo *philo)
{
	print_msg(philo, "is thinking");
}

void	*start_routine(void *argv)
{
	t_philo	*philo;

	philo = argv;
	if (philo->n % 2 == 0)
		ft_usleep(philo->info->time_to_eat);
	while (!philo->info->finish)
	{
		taken_a_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
