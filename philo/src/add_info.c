/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:39:38 by yjung             #+#    #+#             */
/*   Updated: 2021/07/04 18:14:07 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	parsing_info(t_info *info, int argc)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
}

static int	check_info(t_info *info, int argc, char *argv[])
{
	int	status;

	status = 0;
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	if (argc == 6 && info->must_eat <= 0 && ++status >= 0)
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
		if (i == 0)
			info->philos[i].left = &info->forks[info->num_of_philo - 1];
		else
			info->philos[i].left = &info->forks[i - 1];
		info->philos[i].right = &info->forks[i];
		info->philos[i].info = info;
	}
	return (SUCCESS);
}

int	add_info(t_info *info, int argc, char *argv[])
{
	parsing_info(info, argc, argv);
	if (check_info(info, argc))
		return (FAIL);
	if (set_philo_info(info))
		return (FAIL);
	return (SUCCESS);
}

int	ft_malloc(void *dst, size_t size)
{
	*(void **)dst = malloc(size);
	if (*(void **)dst == NULL)
		return (FAIL);
	memset(*(void **)dst, 0, size);
	return (SUCCESS);
}
