##
## EPITECH PROJECT, 2018
## PSU_navy_2017
## File description:
## Makefile for navy project
##

## VARIABLES

NAME 					= 	navy

UNITS 					= 	units

SRC_DIR 				= 	src/

TEST_DIR				= 	tests/

SRC_FILES				= 	main.c 				\
						navy.c 				\
						navy_main.c 			\
						utilities/data_utils.c  	\
						utilities/struct_utils.c 	\
						utilities/std_utils.c 		\
						utilities/get_next_line.c 	\
						utilities/parsing_utils.c 	\
						connector/connector.c 		\
						connector/signals.c 		\
						connector/handlers.c 		\
						map/error/check_map_error.c 	\
						map/error/check_boat_error.c	\
						map/map_creation.c 		\
						map/map_management.c 		\
						map/map_add_boat.c 		\
						map/map_display.c 		\
						game/game_loop.c 		\
						game/check_end_game.c 		\
						game/check_hit_fail.c

SRC					= 	$(addprefix $(SRC_DIR), $(SRC_FILES))

TESTS_FILES				=	$(filter-out main.c, $(SRC_FILES))

TESTS_FILES				+=	navy_wrong_file_tests.c 	\
						navy_correct_execution_tests.c 	\
						navy_utils_tests.c 		\
						navy_arguments_tests.c 		\
						navy_signals_tests.c

INCLUDE					= 	include/

LIBRARY_DIR				= 	lib/

CC					=	gcc

CFLAGS					= 	-Wall -Wextra -I $(INCLUDE)

LFLAGS					= 	-L $(LIBRARY_DIR) -lmy

UNITS_LFLAGS				= 	$(LFLAGS) -lgcov -lcriterion

## BUILD VARIABLES

BUILD_DIR				= 	build/

BUILD_TESTS_DIR				= 	tests/build/

BUILD_OBJ				= 	$(addprefix $(BUILD_DIR), $(SRC_FILES:.c=.o))

BUILD_TESTS_OBJ				= 	$(addprefix $(BUILD_TESTS_DIR), $(TESTS_FILES:.c=.o))

BUILD_SD				= 	$(shell find $(SRC_DIR) -mindepth 1 -type d -printf '%p\n' | sed -e 's/^src\///')

## RULES

all:					library $(BUILD_DIR) $(NAME)

library:
					make -C $(LIBRARY_DIR)

$(BUILD_DIR):
					mkdir -p $(BUILD_DIR)
					$(foreach SUB_DIR, $(BUILD_SD), $(shell mkdir -p $(BUILD_DIR)$(SUB_DIR)))

$(BUILD_DIR)%.o:			$(SRC_DIR)%.c
					$(CC) $(CFLAGS)   -c -o $@ $<

$(NAME):				$(BUILD_OBJ)
					$(CC) $(CFLAGS)   -o $(NAME) $(BUILD_OBJ) $(LFLAGS)

tests_run:				fclean library $(UNITS)
					find $(BUILD_TESTS_DIR) -name '*.gc*' -exec mv -t ./ {} +
					./$(UNITS)

$(UNITS):				$(BUILD_TESTS_DIR) $(BUILD_TESTS_OBJ)
					$(CC) $(CFLAGS)   -o $(UNITS) $(BUILD_TESTS_OBJ) --coverage $(UNITS_LFLAGS)

$(BUILD_TESTS_DIR):
					mkdir -p $(BUILD_TESTS_DIR)$(TEST_DIR)
					$(foreach SUB_DIR, $(BUILD_SD), $(shell mkdir -p $(BUILD_TESTS_DIR)$(SUB_DIR)))

$(BUILD_TESTS_DIR)%.o:	$(SRC_DIR)%.c
					$(CC) $(CFLAGS) --coverage   -c -o $@ $<

$(BUILD_TESTS_DIR)%.o:	$(TEST_DIR)%.c
					$(CC) $(CFLAGS) --coverage   -c -o $@ $<

clean:
					rm -rf $(BUILD_DIR)
					rm -rf $(BUILD_TESTS_DIR)
					find -name '*.gc*' -delete -or -name 'vgcore.*' -delete -o -name '*.o' -delete
					make clean -C $(LIBRARY_DIR)

fclean:					clean
					rm -rf $(NAME)
					rm -rf $(UNITS)
					make fclean -C $(LIBRARY_DIR)

re:					fclean all

# Just in case those files exist in the root dir
.PHONY					: all library clean fclean re tests_run
