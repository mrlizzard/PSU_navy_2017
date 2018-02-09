/*
** EPITECH PROJECT, 2018
** navy
** File description:
** connector functions
*/

# include "navy.h"

bool send_data(char *column)
{
	int bit = get_case_number(column);
	int loop;

	usleep(1000000);
	printf(" => SEND: %d to %d\n", bit, get_receiver_pid());

	for (loop = 0; loop < bit; loop++) {
		printf("%d\n", loop);
		if (kill(data->pid2, SIGUSR1) < 0) {
			write(2, "Unable to send signal to receiver.\n", 35);
			return (false);
		}
		usleep(80000);
	}

	if (kill(data->pid2, SIGUSR2) < 0) {
		write(2, "Unable to send signal to receiver.\n", 35);
		return (false);
	}
			
	return (true);
}

int configure_p2_pid(int sig, void *action)
{
	sigact_t act;

	if (sig == SIGUSR1 || sig == SIGUSR2) {
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		act.sa_sigaction = action;

		if (sigaction(sig, &act, NULL) == -1)
			return (-1);

		return (0);
	}

	return (-1);
}

bool send_signal(int pid, int sig)
{
	int res = -1;

	if (sig != SIGUSR1 && sig != SIGUSR2)
		return (false);

	res = kill(pid, sig);

	return ((res == 0) ? true : false);
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
		if (!send_signal(data->pid2, SIGUSR1)) {
			write(2, "Unable to send signal.\n", 23);
			return (false);
		}
	}

	return (true);
}