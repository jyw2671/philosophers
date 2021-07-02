/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:14:19 by yjung             #+#    #+#             */
/*   Updated: 2021/07/02 20:18:43 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac < 5 || ac > 6)
	{
		printf("Wrong number of arguments\n");
		return (FAIL);
	}
	memset(&info, 0, sizeof(t_info));
	if (add_info(&info, av))
		return (FAIL);
	if (init_philo(&info))
		return (FAIL);
	return (SUCCESS);
}
