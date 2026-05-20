#include <cmath>
#include <cstdio>
#include <windows.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 25

typedef struct SObject {
	float x, y;
	float width, height;
	float vert_speed;
	BOOL is_fly;
	char c_type;
	float horiz_speed;
} TObject;

char map[MAP_HEIGHT][MAP_WIDTH + 1];
TObject mario;
TObject* brick = NULL;
int brick_length = 0;

TObject* moving = NULL;
int moving_length = 0;

int level = 1;
int score = 0;
int max_lvl = 3;

void clear_map();
void show_map();
void set_object_pos(TObject* const obj, const float x_pos, const float y_pos);
void init_object(TObject* const obj, const float x_pos, const float y_pos, const float o_width, const float o_height, const char in_type);
void player_dead(const char* const death_message);
BOOL is_collision(const TObject o1, const TObject o2);
TObject* get_new_moving();
TObject* get_new_brick();
void vert_move_object(TObject* const obj, const bool is_moving_obj);
void delete_moving(const int i);
void mario_collision();
void horizon_move_object(TObject* const obj);
BOOL is_pos_in_map(const int x, const int y);
void put_object_on_map(const TObject obj);
void set_cur(const int x, const int y);
void horizon_move_map(const float dx);
void put_score_on_map(const char* const label);
void create_level(const int lvl, const char* const level_message);