/*
** EPITECH PROJECT, 2018
** navy_2017
** File description:
** navy functions
*/

# include "navy.h"

int game_manager(void)
{
	my_putstr("my_pid: ");
	my_put_nbr(data->pid);
	my_putchar('\n');

	if (!connector()) {
		write(2, "Error during connection.\n", 25);
		return (84);
	}

	if (data->type == playerTwo) {
		if (!send_data("H8"))
			return (84);
	} else
		pause();

	return (data->status);
}

int navy(int ac, char **av)
{
	int st;

	if (!config_struct(ac, av)) {
		my_puterr("Malloc failed. Aborded.\n", false);
		return (84);
	}
	if (data->status != 0) {
		st = data->status;
		free_struct();
		return (st);
	}
	map_creation();
	st = game_manager();
	if (st == 0)
		player_turn();
	st = data->status;
	free_struct();
	return (st);
}
