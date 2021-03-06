/*
** EPITECH PROJECT, 2018
** navy
** File description:
** check_boat_error functions
*/

# include "navy.h"

int cas1(int i)
{
	if (data->info[i][6] > data->info[i][3]) {
		if (data->info[i][0] - 48 -
		(data->info[i][6] - data->info[i][3] + 1) != 0)
			return (-1);
	}
	if (data->info[i][6] < data->info[i][3]) {
		if (data->info[i][0] - 48 -
		(data->info[i][3] - data->info[i][6] +1) != 0)
			return (-1);
	}
	return (0);
}

int cas2(int i)
{
	if (data->info[i][5] > data->info[i][2]) {
		if (data->info[i][0] - 48 -
		(data->info[i][5] - data->info[i][2] +1) != 0)
			return (-1);
	}
	if (data->info[i][6] < data->info[i][3]) {
		if (data->info[i][0] - 48 -
		(data->info[i][2] - data->info[i][5] +1) != 0)
			return (-1);
	}
	return (0);
}

int check_boat_error(void)
{
	int err;
	int i = 0;

	for (i = 0; data->info[i] != NULL; i++) {
		if (data->info[i][5] == data->info[i][2]) {
			err = cas1(i);
		} else if (data->info[i][6] == data->info[i][3]) {
			err = cas2(i);
		}
		if (err == -1)
			return (-1);
	}
	return (0);
}
