/*
** EPITECH PROJECT, 2018
** navy -> criterion units
** File description:
** navy_wrong_file_tests functions
*/

# include "units.h"

Test(wrong_file, unknown_file, .init = redirect_std)
{
	char *args[2];
	int res = -1;

	args[0] = "./navy";
	args[1] = "im_an_non_existant_file";
	res = navy_main(2, args);

	cr_assert_eq(res, 84);
}

Test(wrong_file, out_of_range, .init = redirect_std)
{
	char *args[2];
	int res = -1;

	args[0] = "./navy";
	args[1] = "maps/wrong/pos1";
	res = navy_main(2, args);

	cr_assert_eq(res, 84);
}

Test(wrong_file, out_of_range_two, .init = redirect_std)
{
	char *args[2];
	int res = -1;

	args[0] = "./navy";
	args[1] = "maps/wrong/pos2";
	res = navy_main(2, args);

	cr_assert_eq(res, 84);
}
