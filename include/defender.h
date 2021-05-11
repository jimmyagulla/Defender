/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** defender header
*/

#ifndef defender
#define defender

#include "my.h"

enum defender{menu, option, game, quit,
resize, resized, resize_two, resize_three, quit_game,
game_over, tutorial};

enum direction{UP, RIGHT, LEFT, DOWN};

enum towertype{ARCHER, SLOW, RED, CANON};

typedef struct myclock_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} myclock_t;

typedef struct game_object_s {
    float width;
    float height;
    sfVector2f scale;
    int karim;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    myclock_t clock;
} game_object_t;

typedef struct tower_object_s {
    float width;
    float height;
    sfVector2f scale;
    int price;
    int upgrade_price;
    int upgrade_status;
    int tower_type;
    int range;
    int damage;
    int total_cost;
    int attack_speed;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    myclock_t clock;
} tower_object_t;

typedef struct mobs_object_s {
    float width;
    float height;
    sfVector2f scale;
    int health;
    int karim;
    int status;
    bool reached_castle;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    myclock_t clock;
    myclock_t speed_clock;
    int slow;
} mobs_object_t;

typedef struct gameover {
    game_object_t *game_obj;
    sfMusic *gameover_sound;
} gameover_t;

typedef struct mapchooser {
    int index;
    bool nick_status;
    bool enternick;
    bool choosedmap;
    bool difficulty_map;
    sfColor green;
    sfColor red;
    sfRectangleShape *one;
    sfRectangleShape *two;
    sfRectangleShape *three;
    sfText *nickinput;
    sfText *difficulty;
    sfText *nicktext;
    sfFont *nickfont;
    int choice;
    char *nickname;
    game_object_t *game_obj;
    sfText *diff_txt;
} mapchooser_t;

typedef struct menu {
    game_object_t *settings;
    sfText *highestscore;
    bool fps_status;
    char *highest_score;
    int resizenb;
    sfMusic *menu_sound;
    int sfx_vol;
    int mus_vol;
    int fps;
    float fps_posx;
    float music_posx;
    float sfx_posx;
} menu_t;

typedef struct game {
    int score_nb;
    sfText *score;
    sfText *tower_prices;
    int game_music_volume;
    int game_sound_volume;
    int **spawn_points;
    int nb_spawn_points;
    int difficulty;
    int wave;
    int mb_counter;
    int tower_nb;
    int map_cols;
    int map_lines;
    int castle_health;
    sfCircleShape *circle_range;
    int tower_id;
    int reached_castle;
    int gold_coins;
    int death_counter;
    int clone_mb_reached;
    int clone_death_counter;
    int og_life_width;
    int gold_save;
    int game_speed;
    float starting_onthefloor;
    bool draw_mb;
    bool spawn_mb;
    bool grab_tower;
    bool once;
    bool startwave;
    bool wavefinished;
    bool display_upgrd;
    sfClock *clock_monsters;
    sfTime time_ms;
    float seconds_ms;
    bool show_settings;
    char **map_arr;
    char **tower_arr;
    char *map_buff;
    game_object_t *game_obj;
    tower_object_t *tower;
    mobs_object_t *mobs;
    sfText *health_nb;
    sfText *scorenb;
    sfFont *health_font;
    sfText *gold_nb;
    sfFont *gold_font;
    int total_rcastle;
} game_t;

typedef struct cursor_s {
    game_object_t *gcursor;
} cursor_t;

typedef struct laser {
    sfRectangleShape *laser;
} laser_t;

typedef struct all {
    laser_t *laser;
    int status;
    int pre_status;
    sfMusic *click_sound;
    sfRenderWindow* window;
    menu_t menu[4];
    cursor_t cursor[4];
    game_t game[5];
    gameover_t gameover[1];
    mapchooser_t mapchooser[1];
    sfFont *fps_font;
    sfText *fps_word;
    sfText *fps_nb;
    sfTime fps_time;
    sfClock *fps_clock;
    float width;
    float height;
    int resize_status;
    int game_status;
    bool fdp;
} all_t;

float angle(int id, int i, all_t *all);
void tutorial_loop(all_t *all);
void menu_mouse_tutorial(all_t *all, sfEvent event);
void create_tutorial_sprites(all_t *all);
char *read_myfile_score(char *filepath, all_t *all, int i);
void init_score_texts(all_t *all);
void init_laser(all_t *all);
void draw_difficulty(all_t *all);
void draw_ice_particules(all_t *all, int id);
void draw_red_particules(all_t *all, int id, int i);
void draw_archer_particules(all_t *all, int id, int i);
void draw_canon_particules(all_t *all, int id, int i);
void click_difficultyr_event(all_t *all, sfEvent event);
void click_difficultyl_event(all_t *all, sfEvent event);
void init_sftext_difficulty(all_t *all);
void draw_final_score(all_t *all);
void while_nick_status(all_t *all);
int get_player_nickname(all_t *all, sfEvent event);
void click_mapone_event(all_t *all, sfEvent event);
void click_mapthree_event(all_t *all, sfEvent event);
void click_maptwo_event(all_t *all, sfEvent event);
bool check_string_char(char *str, char c);
void draw_score(all_t *all);
void create_mapchooser_sprites(all_t *all);
void create_gameover_sprites(all_t *all);
void init_sftext(all_t *all);
void upgrade_canon_lvlthree(all_t *all);
void upgrade_red_lvlthree(all_t *all);
void upgrade_ice_lvlthree(all_t *all);
void upgrade_archer_lvlthree(all_t *all);
void upgrade_canon_lvltwo(all_t *all);
void click_mapone_scale_event(all_t *all, sfEvent event);
void draw_mapchooser_sprites(all_t *all);
void upgrade_red_lvltwo(all_t *all);
void upgrade_ice_lvltwo(all_t *all);
void upgrade_archer_lvltwo(all_t *all);
void menu_button_mouse(all_t *all, sfEvent event, sfVector2i mvector);
void restart_button_mouse(all_t *all, sfEvent event, sfVector2i mvector);
void gameover_loop(all_t *all);
void start_wave(all_t *all);
void display_upgrade(all_t *all);
void init_game_hehe(all_t *all);
void create_prices(all_t *all);
void create_pause_sprites_two(all_t *all);
void display_level_two_board(all_t *all);
void display_tower_upgrd_window(all_t *all);
void change_tower_rect(all_t *all);
void display_tower_upgrd_window(all_t *all);
void handle_towers_placements(all_t *all, sfVector2i mvector);
void draw_game_map(all_t *all);
void draw_tower_range(all_t *all, tower_object_t tower, sfVector2i mvector);
void draw_game_ui(all_t *all);
void handle_game_event(all_t *all);
void handle_escape_key(all_t *all, sfEvent event);
void show_settings(all_t *all, sfEvent event);
void handle_towers(all_t *all, sfEvent event, sfVector2i mvector);
void play_clicksound(all_t *all);
void map_choser(all_t *all);
void restart_wave(all_t *all);
void get_monsters_directions(all_t *all);
void set_tower_positions(all_t *all, sfVector2i mvector);
void init_values(all_t *all);
void rezize_sprites(all_t *all);
void rezize_sprites_two(all_t *all);
void archer_tower(all_t *all, sfEvent event);
void alarm_tower(all_t *all, sfEvent event);
void archer_tower(all_t *all, sfEvent event);
void red_tower(all_t *all, sfEvent event);
void canon_tower(all_t *all, sfEvent event);
int handle_upgrades_event(all_t *all, sfEvent event);
void handle_clock_monsters(all_t *all);
void get_path_pos(all_t *all);
void draw_mobs(all_t *all, int i);
int draw_map(all_t *all);
int read_myfile(char *filepath, all_t *all);
int my_lenght(char *filepath);
int loop_map(all_t *all);
void get_path_pos(all_t *all);
void move_monsters(all_t *all, int id);
int get_randoms(int lowest, int highest, int counter);
void resume_button(all_t *all, sfEvent event);
void quit_gbutton(all_t *all, sfEvent event);
void menu_button(all_t *all, sfEvent event);
void option_gbutton(all_t *all, sfEvent event);
void get_monsters_directions(all_t *all);
void handle_cursor_hand_menu(all_t *all);
void handle_cursor_hand_option(all_t *all);
void init_game_object(game_object_t *obj, char *filepath);
void init_clock(myclock_t *clock);
void tower_hit_mobs(all_t *all);
void init_tower_object(tower_object_t *object, char *filepath);
void init_tower_clock(myclock_t *clock);
int mobs_per_waves(all_t *all, int wave);
void health_display(all_t *all);
void map_size(all_t *all);
void destroy_menu_assets(all_t *all);
void init_mobs_object(mobs_object_t *object, char *filepath);
void destroy_options_assets(all_t *all);
void draw_gold(all_t *all);
void draw_health(all_t *all);
void create_ui_sprites(all_t *all);
float get_mobs_lifebarlen(mobs_object_t mob, int og_w, all_t *all);
void accelerate_button_mouse(all_t *all, sfEvent event, sfVector2i mvector);
void play_button_mouse(all_t *all, sfEvent event, sfVector2i mvector);
void board_loop(all_t *all);

/*<----------------------------------------->*/
/*<---------- DEFENDER FUNCTIONS ---------->*/
/*<--------------------------------------->*/
void draw_cursor(all_t *all);
void create_cursor(all_t *all);
void init_var(all_t *all);
int handle_args(int argc, char **argv);
void main_loop(all_t *all);

/*<----------------------------------------->*/
/*<------------ GAME FUNCTIONS ------------>*/
/*<--------------------------------------->*/
/* _________INIT__________ */
void create_game_sprites(all_t *all);
void init_monsters(all_t *all);
/* _________ATTACK__________ */
int hit_bot_left(all_t *all, int i);
int hit_bot_right(all_t *all, int i);
int hit_top_left(all_t *all, int i);
int hit_top_right(all_t *all, int i);
/* _________OTHER__________ */
void game_loop(all_t *all);

/*<----------------------------------------->*/
/*<------------ MENU FUNCTIONS ------------>*/
/*<--------------------------------------->*/
/* _________INIT__________ */
void create_sprites_menu(all_t *all);
void create_menu_clocks(all_t *all);
void create_menu(all_t *all);
void assign_clock(all_t *all);
void my_clock(all_t *all);
void my_clock_two(all_t *all);
void my_clock_three(all_t *all);
void repeat_textures_menu(all_t *all);
/* _________BUTTONS__________ */
void menu_buttons(all_t *all, sfEvent event);
void play_button(all_t *all);
void option_button(all_t *all);
void quit_button(all_t *all);
/* _________OTHER__________ */
void menu_mouse(all_t *all, sfEvent event);
void menu_loop(all_t *all);
int handle_menu_event(all_t *all);

/*<--------------------------------------------->*/
/*<------------ SETTINGS FUNCTIONS ------------>*/
/*<------------------------------------------->*/
/* _________INIT__________ */
sfRenderWindow *create_window(all_t *all, int width, int length,
sfUint32 style);
void create_settings_sprites(all_t *all);
/* _________BUTTONS__________ */
void handle_button_one(all_t *all, sfEvent event);
void handle_button_two(all_t *all, sfEvent event);
void handle_button_three(all_t *all, sfEvent event);
void return_button_event(all_t *all);
/* _________SLIDERS__________ */
void handle_slider_one(all_t *all);
void handle_slider_two(all_t *all);
void handle_slider_three(all_t *all);
void option_loop(all_t *all);
int option_mouse(all_t *all, sfEvent event);

void fps_display(all_t *all);
void grab_fps(all_t *all);
void draw_fps(all_t *all);
void handle_fps_events(all_t *all, sfEvent event);

/*<----------------------------------------->*/
/*<------------ UTILITY FUNCTIONS ------------>*/
/*<--------------------------------------->*/
float cross(float value, all_t *all, char h);
int calc_volume(all_t *all);
int calc_fps(all_t *all);
int calc_sfx(all_t *all);
void init_clock(myclock_t *clock);

#endif