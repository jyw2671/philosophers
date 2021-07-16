/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:19:14 by yjung             #+#    #+#             */
/*   Updated: 2021/07/16 15:11:21 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPE_H
# define PHILO_TYPE_H

# define SUCCESS	0
# define FAIL		1

# define DIED		1
# define FULL		2

typedef struct s_philo
{
	int				n;
	int				num_of_eat;
	int				left;
	int				right;
	pthread_mutex_t	check_mutex;
	pthread_t		thread;
	struct s_info	*info;
	long long		last_time_to_eat;
}	t_philo;

typedef struct s_info
{
	int				num_of_philo;
	int				num_of_finish_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				finish;
	pthread_mutex_t	finish_mutex;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	long long		time;
}	t_info;

#endif
