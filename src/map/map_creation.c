/*
** EPITECH PROJECT, 2018
** navy
** File description:
** map_creation functions
*/

# include "navy.h"

char **map_alpha_nb(char **map)
{
	int nb = 49;
	int alpha = 65;
	int i = 0;

	for (i = 2; i < 17; i++) {
		if (i % 2 == 0) {
			map[0][i] = alpha;
			alpha++;
		} else
			map[0][i] = ' ';
	}
	for (i = 2; i < 10; i++) {
		map[i][0] = nb;
		nb++;
	}
	return (map);
}

char **map_empty_board(char **map)
{
	int i = 0;
	int j = 0;

	for (i = 2; i < 10; i++)
		for (j = 2; j < 17; j++) {
			if (j % 2 == 0) {
				map[i][j] = '.';
			} else
				map[i][j] = ' ';
		}
	return (map);
}

char **map_fill(char **map)
{
	int i = 0;

	for (i = 0; i < 10; i++) {
		map[i] = malloc(sizeof(char) * 18);
		map[i][17] = '\0';
		map[i][1] = '|';
	}
	for (i = 0; i < 17 ; i++)
		map[1][i] = '-';
	map[0][0] = ' ';
	map[1][1] = '+';
	map_alpha_nb(map);
	map_empty_board(map);
	return (map);
}

void map_creation(void)
{
	data->map = malloc(sizeof(char *) * 11);
	data->map[10] = NULL;
	data->map = map_fill(data->map);
	data->enemy = malloc(sizeof(char *) * 11);
	data->enemy[10] = NULL;
	data->enemy = map_fill(data->enemy);
	data->map = map_add_boat(data->map);
}
