//
//  io.h
//  Lab 2 Pong Game
//
//  Created by Nathan Hung on 2024-09-11.
//  Modified by Salma Emara on 2024-09-11
//  Copyright © 2024 Nathan Hung. No rights reserved.
//
//
// ***********  ECE244 Student: DO NOT MODIFY THIS FILE  ***********

#ifndef UTIL_H
#define UTIL_H

#include <sys/ioctl.h>  // For FIONREAD
#include <termios.h>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#include <ctype.h>
#include <sstream>
#include "Globals.h"

// Function declarations
// int kbhit(void);
char get_input(void);
void eraseLines(int count);
// void clear(void);
// std::string colored_string(const std::string text);
// std::string colored_string(const std::string text, const int rgb[3]);
std::string get_past_inputs();

#endif  // UTIL_H
