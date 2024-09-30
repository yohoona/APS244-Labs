//
//  Ball.cpp
//  Lab 2 Pong Game
//
//  Created by Jihoon You, Sept 2024
#include "Ball.h"
#include <iostream>
using namespace std;
//#define SQRT2 1.41421356237

Ball::Ball() {
    velocity_x = 0;
    velocity_y = 0;
    x = 0;
    y = 0;
    width = 1;
    height = 1;
    id = 0;
}

Ball::Ball(double x, double y, double velocity_x, double velocity_y, int id) {
    this->x = x;
    this->y = y;
    this->velocity_x = velocity_x;
    this->velocity_y = velocity_y;
    this->id = id;
    width = 1;
    height = 0;
}

double Ball::getX() {
    return x;
}

int Ball::getID() {
    return id;
}

void Ball::update() {
    velocity_y -= 0.02 * timeStep;
    x += velocity_x * timeStep;
    y += velocity_y * timeStep;
}

int Ball::overlap(Ball& b) {
    bool isOverlap = false;
    
    if (sqrt(2) >= sqrt((pow(b.x - x, 2) + pow(b.y - y, 2)))) {
        isOverlap = true;
    }

    if (isOverlap && abs(b.x - x) <= abs(b.y - y)) {
        return HORIZONTAL_OVERLAP;
    } else if (isOverlap && abs(b.x - y) > abs(b.y - y)) {
        return VERTICAL_OVERLAP;
    }

    if (!isOverlap) {
        return NO_OVERLAP;
    }
   
    // figure this out and im done
    /*if (b.x <= x + width && b.y <= y + height) {
        isOverlap = true;
    }

    if (isOverlap && (x + width - b.x) >= (y + height - b.y)) {
        return HORIZONTAL_OVERLAP;
    } else if (isOverlap && (x + width - b.x) < (y + height - b.y)) {
        return VERTICAL_OVERLAP;
    }

    if (!isOverlap) {
        return NO_OVERLAP;
    }*/
}

int Ball::overlap(Player& p) {
    bool isOverlap = false;
    if (p.getX() <= x && p.getX() + p.getWidth() >= x + height && p.getY() <= y && p.getY() + p.getHeight() >= y + height) { // i know this is wrong / can be optimized but my program breaks when i mess with this line in any way
        isOverlap = true;
    }

    if (isOverlap) {
        return HORIZONTAL_OVERLAP;
    } else {
        return NO_OVERLAP;
    }
}

void Ball::bounce(Ball arr[], int ballCount, Player player) {
    // case 1 : wall
    if (x <= 0 || x >= WIDTH - 1) {
        velocity_x *= -1;
    } if (y <= 0 || y >= HEIGHT - 1) {
        velocity_y *= -1;
    }

    // case 2 : paddle
    if (overlap(player) != NO_OVERLAP) {
        velocity_x *= -1;
    }

    // case 3 : ball
    for (int i = 0; i < ballCount; ++i) {
        if (i != id && overlap(arr[i]) == HORIZONTAL_OVERLAP) {
            velocity_x *= -1;
        } else if (i != id && overlap(arr[i]) == VERTICAL_OVERLAP) { // this used to be just } if and not elif
            velocity_y *= -1;
        }
    }
}

void Ball::draw(Screen& screen_to_draw_to) {
    screen_to_draw_to.addPixel(x, y, 'o');
}