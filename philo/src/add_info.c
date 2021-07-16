/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:39:38 by yjung             #+#    #+#             */
/*   Updated: 2021/07/16 18:07:44 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_malloc(void *dst, size_t size)
{
	*(void **)dst = malloc(size);
	if (*(void **)dst == NULL)
		return (FAIL);
	memset(*(void **)dst, 0, size);
	return (SUCCESS);
}

static int	check_info(t_info *info, int ac, char *av[])
{
	int	status;

	status = 0;
	info->num_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	if (ac == 6 && info->must_eat <= 0 && ++status >= 0)
		printf("ERROR: wrong num of must eat\n");
	if (info->num_of_philo < 0 && ++status >= 0)
		printf("ERROR: wrong num of philo\n");
	if (info->time_to_die < 0 && ++status >= 0)
		printf("ERROR: wrong time to die\n");
	if (info->time_to_eat < 0 && ++status >= 0)
		printf("ERROR: wrong time to eat\n");
	if (info->time_to_sleep < 0 && ++status >= 0)
		printf("ERROR: wrong time to sleep\n");
	if (status != 0)
		return (FAIL);
	return (SUCCESS);
}

static int	set_philo_info(t_info *info)
{
	int		i;

	pthread_mutex_init(&info->finish_mutex, NULL);
	if (ft_malloc(&info->philos, sizeof(t_philo) * info->num_of_philo) || \
		ft_malloc(&info->forks, sizeof(pthread_mutex_t) * info->num_of_philo))
	{
		printf("ERROR: malloc failed\n");
		return (FAIL);
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philos[i].n = i;
		pthread_mutex_init(&info->forks[i], NULL);
		pthread_mutex_init(&info->philos[i].check_mutex, NULL);
		info->philos[i].left = (i + 1) % info->num_of_philo;
		info->philos[i].right = i;
		info->philos[i].info = info;
	}
	return (SUCCESS);
}

int	add_info(t_info *info, int ac, char *av[])
{
	if (check_info(info, ac, av))
		return (FAIL);
	if (set_philo_info(info))
		return (FAIL);
	return (SUCCESS);
}
