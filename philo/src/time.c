/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:45:10 by yjung             #+#    #+#             */
/*   Updated: 2021/07/16 15:18:27 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = ms_time(time);
	return (ms);
}

long long	ms_time(struct timeval time)
{
	long long	ms_time;

	ms_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms_time);
}

void	ft_usleep(int num)
{
	long long	time;

	time = get_time();
	while (get_time() - time <= num)
		usleep(1000);
}
