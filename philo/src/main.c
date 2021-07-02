/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:14:19 by yjung             #+#    #+#             */
/*   Updated: 2021/07/02 18:26:13 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_routine(void *args)
{

}

int	init_philo(t_info *info)
{
	pthread_t	thread;
	int			i;

	gettimeofday(&info->time, NULL);
	while (++i < info->num_of_philo)
	{
		info->philos[i].last_time_to_eat = info->time;
		if (pthread_create(&thread, NULL, \
			start_routine, (void*)&info->philos[i]))
			return (FAIL);
		pthread_detach(thread);
		if (pthread_create(&info->philos[i].thread, NULL, \
			&is_he_dead, (void*)&info->philos[i]))
			return (FAIL);
	}
	return (SUCCESS);
}

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac < 5 || ac > 6)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (FAIL);
	}
	memset(&info, 0, sizeof(t_info));
	if (add_info(&info, av))
		return (FAIL);
	return (SUCCESS);
}
