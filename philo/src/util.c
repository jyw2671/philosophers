/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:29:00 by yjung             #+#    #+#             */
/*   Updated: 2021/07/16 15:06:50 by yjung            ###   ########.fr       */
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

void	print_msg(t_philo *philo, char *str, int status)
{
	pthread_mutex_lock(&philo->info->finish_mutex);
	if (philo->info->finish)
	{
		pthread_mutex_unlock(&philo->info->finish_mutex);
		return ;
	}
	if (status == FULL)
		printf("%lld\tall philosopers have eaten enough", \
		get_time() - philo->info->time);
	else
		printf("%lld\t%d\t %s\n", get_time() - philo->info->time, \
			philo->n + 1, str);
	pthread_mutex_unlock(&philo->info->finish_mutex);
}

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->info->forks[philo->left]));
	pthread_mutex_unlock(&(philo->info->forks[philo->right]));
}
