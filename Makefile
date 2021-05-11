##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my make file
##

NAME	=	my_defender

SRCS	= 	./src/main.c	\
			./src/utility/handle_args.c	\
			./src/handle_window.c	\
			./src/utility/init_window.c	\
			./src/utility/window_utilities.c	\
			./src/handle_menu_status.c	\
			./src/menu/menu_buttons.c	\
			./src/menu/create_menu_sprites.c	\
			./src/menu/menu_clocks.c	\
			./src/menu/tutorial_events.c	\
			./src/menu/tutorial_loop.c	\
			./src/options/handle_options_status.c	\
			./src/options/handle_settings_sliders.c	\
			./src/options/handle_settings_buttons.c	\
			./src/options/slider_utilities.c	\
			./src/handle_game_status.c	\
			./src/events/handle_events.c	\
			./src/menu/handle_menu_mouse.c	\
			./src/utility/handle_fps.c	\
			./src/options/create_settings_sprites.c	\
			./src/game/backend/init_game_sprites.c	\
			./src/utility/read_map.c	\
			./src/menu/destroy_assets.c	\
			./src/utility/handle_cursor.c	\
			./src/menu/menu_clocks_two.c	\
			./src/utility/game_object.c	\
			./src/game/backend/game_settings_buttons.c	\
			./src/game/backend/mobs/move_monsters.c	\
			./src/game/backend/init_waves.c	\
			./src/game/backend/mobs/mobs_spawn_wave.c	\
			./src/game/frontend/draw_mobs.c	\
			./src/game/backend/mobs/handle_spawn_points.c	\
			./src/game/backend/init_mobs_tower.c	\
			./src/game/backend/tower/handle_towers_attack.c	\
			./src/game/backend/tower/tower_hits_mobs.c	\
			./src/game/frontend/user_interface/handle_ui_display.c	\
			./src/game/frontend/user_interface/create_ui_sprites.c	\
			./src/game/frontend/user_interface/handle_lifebars.c	\
			./src/options/resize_options.c	\
			./src/menu/handle_menu_cursor.c	\
			./src/game/backend/init_var.c	\
			./src/game/frontend/user_interface/handle_game_buttons.c	\
			./src/game/backend/mobs/get_mobs_dir.c	\
			./src/game/backend/tower/handle_red_tower.c	\
			./src/game/backend/tower/handle_alarm_tower.c	\
			./src/game/backend/tower/handle_canon_tower.c	\
			./src/game/backend/tower/handle_archer_tower.c	\
			./src/game/backend/tower/handle_towers.c	\
			./src/game/backend/tower/handle_towers_upgrade_event.c	\
			./src/game/backend/tower/place_tower.c	\
			./src/game/backend/tower/draw_tower_circle.c	\
			./src/game/backend/tower/handle_tower_upgrade_two.c	\
			./src/game/frontend/user_interface/display_towers_upgrade.c	\
			./src/game/frontend/user_interface/display_towers_upgrade_two.c	\
			./src/game/frontend/user_interface/create_ui_sprites_two.c	\
			./src/game/backend/tower/up_tower_stats.c	\
			./src/game/backend/tower/up_tower_stats_two.c	\
			./src/game/frontend/user_interface/display_boards.c	\
			./src/game/map_chooser/map_chooser_loop.c	\
			./src/game_over/create_gameover_sprites.c	\
			./src/game_over/gameover_loop.c	\
			./src/game_over/gameover_buttons_events.c	\
			./src/game_over/keep_score.c	\
			./src/game/backend/score.c	\
			./src/game/map_chooser/create_mapchooser_sprites.c	\
			./src/game/frontend/draw_particules.c	\
			./src/game/map_chooser/nickname_text.c	\
			./src/game/map_chooser/handle_mapchooser_maps_events.c	\
			./src/game/map_chooser/draw_sprites.c	\
			./src/game/map_chooser/choose_difficulty_event.c	\
			./src/utility/utility_func.c	\

OBJS	=	$(SRCS:.c=.o)

NBR_OF_FILES := $(words $(SRCS))

CC = gcc

RM	=	rm -f

COMPIL		=	make -C ./lib/my

CFLAGS += -I ./include/ -L./lib/ -lmy
CFLAGS += -W -Wall -Wextra -g3
CFLAGS += -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

all:	$(NAME)

$(NAME):	$(OBJS)
			$(COMPIL)
			@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(NBR_OF_FILES)\033[0m"
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
			@ echo "\033[1;34mBinary : \033[1;32m$(NAME)\033[1;34m created sucesfully.\033[0m"

clean:
		@ echo "\033[3;31mRemoving: \033[0m"
		@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJS)

fclean:	clean
		@ echo "\033[3;31m./$(NAME)\033[0m"
		@ $(RM) $(NAME)
		@	make fclean -C ./lib/my

re: 	fclean all

%.o:	%.c
		@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
		@ $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re