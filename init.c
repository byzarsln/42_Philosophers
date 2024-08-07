#include "philo.h"

int	init_philos(t_data *data)
{
	int i;

	i = 0;
	while(i <= data->number_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].time_of_last_meal = data->start_time;
		data->philo[i].nbr_of_meals = 0;
		data->philo[i].is_eating = false;
		data->philo[i].end = false;
		i++;
	}
	return(EXIT_SUCCESS);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->number_of_philo = ft_atol(argv[1]);
	data->timo_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->nbr_of_times_eat = ft_atol(argv[5]);
	else
		data->nbr_of_times_eat = -1;
	data->start_time = get_time();
	data->end = false;
	return(EXIT_SUCCESS);
}


int	init_all(t_data *data, int argc, char **argv)
{
	if (init_data(data, argc, argv))
		return (EXIT_FAILURE);
	if (init_philos(data))
		return (EXIT_FAILURE);
	if (init_forks(data))
		return (EXIT_FAILURE);
	if (init_mutex(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
