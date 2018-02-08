/*
** EPITECH PROJECT, 2018
** navy_2017
** File description:
** navy functions
*/

# include "navy.h"

static void free_all(void)
{
	free_p1(data->p1);
	free_p2(data->p2);
	my_freetab(data->info);
	free(data);
}

int game_manager(void)
{
	my_putstr("my_pid: ");
	my_put_nbr(data->pid);
	my_putchar('\n');

	if (!connector()) {
		write(2, "Error during connection.\n", 25);
		return (84);
	}

	return (data->status);
}

int navy(int ac, char **av)
{
	int st;

	config_struct(ac, av);
	if (data == NULL) {
		my_puterr("Malloc failed. Aborded.\n", false);
		return (84);
	}
	if (data->status != 0) {
		free_all();
		return (data->status);
	}
	st = game_manager();
	free_all();
	return (st);
}
