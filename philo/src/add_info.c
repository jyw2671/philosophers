/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:39:38 by yjung             #+#    #+#             */
/*   Updated: 2021/07/02 18:00:36 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_int(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (FAIL);
	}
	return (SUCCESS);
}

static int	check_num(char *str, long long *num, t_philo *ph)
{
	if (!is_int(str))
		return (FAIL);
	*num = ft_atoi(str);
	if (*num > __INT_MAX__ || *num < (-__INT_MAX__ - 1))
		return (FAIL);
	return (SUCCESS);
}

static void	store_info(t_info **info, long long num, int status)
{
	if (status == NUM_OF_PHILO)
		(*info)->num_of_philo = num;
	else if (status == TIME_TO_DIE)
		(*info)->time_to_die = num;
	else if (status == TIME_TO_EAT)
		(*info)->time_to_eat = num;
	else if (status == TIME_TO_SLEEP)
		(*info)->time_to_sleep = num;
	else if (status == MUST_EAT)
		(*info)->must_eat = num;
}

static int	check_info(t_info **info, char *av, int status)
{
	char		**tmp;
	long long	num;
	int			i;

	tmp = ft_split(av, ' ');
	i = -1;
	while (tmp[++i])
	{
		if (!check_num(tmp[i], &num, *info))
			return (free_split(&tmp));
		store_info(info, num, status);
		free(tmp[i]);
	}
	free(tmp);
	return (1);
}

int	add_info(t_info **info, char *av[])
{
	int		i;

	i = 0;
	while (av[++i])
	{
		if (!check_info(info, av[i], i))
			return (FAIL);
	}
	return (SUCCESS);
}
