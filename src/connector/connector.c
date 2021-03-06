/*
** EPITECH PROJECT, 2018
** navy
** File description:
** connector functions
*/

# include "navy.h"

void reset_receivement(void)
{
	data->received = false;
	data->data = 0;
}

bool send_signal(int pid, int sig)
{
	int res = -1;

	if (sig != SIGUSR1 && sig != SIGUSR2 && sig != SIGINT)
		return (false);

	res = kill(pid, sig);

	return ((res == 0) ? true : false);
}

bool send_response(int resp)
{
	int loop;

	if (resp != 1 && resp != 2) {
		write(2, "Invalid response.\n", 18);
		return (false);
	}
	for (loop = 0; loop < resp; loop++) {
		if (!send_signal(data->pid2, SIGUSR1)) {
			write(2, "Unable to send signal to receiver.\n", 35);
			return (false);
		}
		usleep(8000);
	}
	if (!send_signal(data->pid2, SIGUSR2)) {
		write(2, "Unable to send signal to receiver.\n", 35);
		return (false);
	}
	usleep(8000);
	return (true);
}

bool send_data(char *column)
{
	int bit = get_case_number(column);
	int loop;

	for (loop = 0; loop < bit; loop++) {
		if (!send_signal(data->pid2, SIGUSR1)) {
			write(2, "Unable to send signal to receiver.\n", 35);
			return (false);
		}
		usleep(8000);
	}
	if (!send_signal(data->pid2, SIGUSR2)) {
		write(2, "Unable to send signal to receiver.\n", 35);
		return (false);
	}
	usleep(8000);
	return (true);
}

bool connector(void)
{
	if (data->type == playerOne) {
		my_putstr("waiting for enemy connection...\n");
		get_player_pid();
		pause();
		if (data->pid2 < 0)
			return (false);
	} else {
		if (data->pid2 < 0)
			return (false);

		if (!send_signal(data->pid2, SIGUSR1)) {
			write(2, "Unable to send signal.\n", 23);
			return (false);
		}
		my_putstr("successfully connected\n\n");
	}
	return (true);
}
