/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:56:08 by yjung             #+#    #+#             */
/*   Updated: 2021/07/16 16:32:58 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	end_philo(t_info *info)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < info->num_of_philo)
// 	{
// 		pthread_join(info->philos[i].thread, NULL);
// 		pthread_mutex_destroy(&info->philos[i].check_mutex);
// 	}
// 	free(info->philos);
// 	i = -1;
// 	while (++i < info->num_of_philo)
// 		pthread_mutex_destroy(&info->forks[i]);
// 	free(info->forks);
// }

void	end_philo(t_info *info)
{
	int	i;

	usleep(2000);
	i = -1;
	pthread_mutex_destroy(&info->finish_mutex);
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&info->philos[i].check_mutex);
	free(info->philos);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&info->forks[i]);
	free(info->forks);
}
