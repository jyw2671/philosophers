/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:06:17 by yjung             #+#    #+#             */
/*   Updated: 2021/07/02 21:00:06 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	taken_a_fork(t_philo *philo)
{
	print_msg(philo, "has taken a fork");
}

static void	eating(t_philo *philo)
{
	print_msg(philo, "is eating");
	usleep(philo->info->time_to_eat * 1000);
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
