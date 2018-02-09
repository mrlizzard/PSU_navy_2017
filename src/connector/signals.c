/*
** EPITECH PROJECT, 2018
** navy
** File description:
** signals function
*/

# include "navy.h"

void sigusr_receiver(int sig, siginfo_t *si, void *ptr)
{
	int d = 0;
	(void)ptr;
	(void)si;

	printf("received\n");

	if (sig == SIGUSR1) {
		d = data->received++;
		printf(" => GET: value=%d\n", d);
		//configure_sig(SIGUSR1, sigusr_receiver);
		pause();
	} else if (sig == SIGUSR2) {
		printf("%s\n", " => GET: end");
		//configure_sig(SIGUSR2, sigusr_receiver);
	}
}

void get_player_pid(void)
{
	sigact_t act;

	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = pid_handler;

	if (sigaction(SIGUSR1, &act, NULL)) {
		write(2, "Invalid sigaction method.\n", 26);
		data->pid2 = -1;
		return;
	}
}