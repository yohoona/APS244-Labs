//
//  Screen.h
//  Lab 2 Pong Game
//
//  Created by Nathan Hung on 2024-09-11.
//  Modified by Salma Emara on 2024-09-11
//  Copyright © 2024 Nathan Hung. No rights reserved.
//
//
// ***********  ECE244 Student: DO NOT MODIFY THIS FILE  ***********

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include "Globals.h"
#include "io.h"

class Screen {
public:
    Screen();
    void update(std::string message);
    void addPixel(double x, double y, char symbol);

private:
    void putLineToBuffer(const std::string& line);
    void renderScreen(); 
    void showFrame();
    void clear_array2d();
    void deleteCurrentlyShownFrame();
    int printed_line_counter;
    int frameNumber; // no need to worry about program running for more than 50,000 hours, so dont worry about overflow
    std::string buffer;
    char array2d[HEIGHT][WIDTH];

};


#endif // SCREEN_H
