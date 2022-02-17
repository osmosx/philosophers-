/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:49:03 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/09 17:49:21 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	thread_create(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philo[i].run_time = get_time();
		if ((pthread_create(&data->philo[i].thread, NULL,
					philo_actions, &data->philo[i])) != 0)
			return ;
		pthread_detach(data->philo[i].thread);
		i++;
	}
	if (end_of_life(data) == 1)
		return ;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check(argc, argv))
		return (printf("Error\n"));
	init(argc, argv, &data);
	thread_create(&data);
	return (0);
}
