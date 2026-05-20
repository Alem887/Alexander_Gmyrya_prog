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
