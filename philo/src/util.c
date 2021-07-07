/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:29:00 by yjung             #+#    #+#             */
/*   Updated: 2021/07/07 20:55:35 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long long	ft_atoi(const char *nptr)
{
	long long	result;
	int			flag;

	result = 0;
	flag = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			flag *= -1;
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += *nptr++ - '0';
	}
	return (result * flag);
}

void	print_msg(t_philo *philo, char *str)
{
	long long		ms;
	struct timeval	curr_time;

	pthread_mutex_lock(&philo->info->finish_mutex);
	gettimeofday(&curr_time, NULL);
	ms = ms_time(curr_time) - ms_time(philo->info->time);
	if (!philo->info->finish)
		printf("%lld\t%d\t %s\n", ms, philo->n + 1, str);
	pthread_mutex_unlock(&philo->info->finish_mutex);
}
