//
//  Player.cpp
//  Lab 2 Pong Game
//
//  Created by Jihoon You, Sept 2024
#include "Player.h"

Player::Player() {
    x = 0;
    y = 0;
    height = 0;
    width = 1;
}

Player::Player(double x, double y, int height) {
    this->x = x;
    this->y = y;
    this->height = height;
    width = 1;
}

double Player::getX() {
    return x;
}

double Player::getY() {
    return y;
}

int Player::getHeight() {
    return height;
}

int Player::getWidth() {
    return width;
}

void Player::decreaseHeight(int delta_to_decrease_by) {
    if (height > 3) {
        height -= delta_to_decrease_by;
    }
}

void Player::update(char c) {
    if (c == 'A' && y + height <= HEIGHT - 3) {
        y += 2;
    } else if (c == 'A' && y + height > HEIGHT - 3) {
        y += HEIGHT - 1 - (y + height);
    } else if (c == 'B' && y >= 2) {
        y -= 2;
    } else if (c == 'B' && y < 2) {
        y -= y;
    }
}

void Player::draw(Screen& screen_to_draw_to) {
    for (int i = 0; i < height; ++i) {
        screen_to_draw_to.addPixel(x, y + i, '#');
    }
}
