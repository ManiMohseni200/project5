#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <deque>
#include <chrono>
#include <fstream>
#include <iostream>
#include <math.h>
#include <random>
#include <stdexcept>
#include <vector>
#include <string>
#include <utility>
using namespace sf;
using namespace std;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const float PI = acos(-1);
const int WIDTH = 1400;
const int HEIGHT = 600;
const int FRAME_RATE = 144;
const string PICS_PATH = "./files/pics/", AUDIO_PATH = "./files/audios/", FONTS_PATH = "./files/fonts/";
const Color BLUE = Color(50, 115, 220);
const Color PURPLE = Color(130, 50, 220);
const Color YELLOW = Color(225, 248, 220);

#define debug(x) cout << x << endl, exit(0);