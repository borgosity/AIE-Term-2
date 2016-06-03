#pragma once

#include <math.h>

const int SCREEN_W = 1280;
const int SCREEN_H = 720;

const int HALF_SW = SCREEN_W >> 1;
const int HALF_SH = SCREEN_H >> 1;

const int SPEED = 2;
const int GRAVITY = 1;
const int FRICTION = -8;
const int BOUNCE = 5;

const float TURN_LEFT = 0.3f;
const float TURN_RIGHT = -0.3f;

// variables for things in the world
const float PLAYER_SIZE = 100;
const float PLAYER_EDGE = PLAYER_SIZE/2;
const int PLAYER_HEALTH = 100;

const int OBJECT_COUNT = 10;
const int OBJECT_SPAWN = 2;
const int MAX_RESPAWN = 3;
const float OBJECT_SIZE = 100;
const float OBJECT_EDGE = OBJECT_SIZE/2;


const float WALL_EDGE = 20;

// variables for the game

const float SIZE_BONUS = 1;
const float SIZE_PENALTY = -2;


