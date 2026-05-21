#pragma once

#include "Map.hpp"
#include "Mario.hpp"
#include "Brick.hpp"
#include "Moving.hpp"

class Game {
private:
    Map map_obj;
    Mario mario;
    Sobject* brick;
    SObject* moving;
    
    int brick_length;
    int moving_length;
    int level;
    int score;
    int max_lvl;

public:
    Game();
    ~Game();
    
    void create_level(const int lvl);
    void player_dead();
    void horizon_move_map(const float dx);
    Brick* get_new_brick(SObject*& brick_ref, int& brick_len);
    Moving* get_new_moving(Sobject*& moving_ref, int& moving_len);
    void delete_moving(SObject*& moving_ref, int& moving_len, const int i);
    
    void run();
};
