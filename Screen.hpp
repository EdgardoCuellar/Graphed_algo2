#ifndef SDL2_TEST_SCREEN_HPP
#define SDL2_TEST_SCREEN_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <array>
#include "Line.h"
#include <random>
#include <vector>
#include <cmath>

// OPTION
int const WITDH = 1000;
int const HEIGHT = 1000;
int const COLORS[4][3] = {{30,30,30}, {250,250,250}, {129, 212, 250}, {98, 0, 234}};
int const NB_LINE = WITDH/100;
float const SIZE = 100;
int const SPEED = 2;

class Screen{
    // BASICS
    bool isRunning{};
    SDL_Window *window{};
    SDL_Renderer *renderer{};

    // SPECIAL
    bool isStart = false;
    std::vector<float> lines;
    std::vector<Line> base;
    int counter = 0;

public:
    Screen () noexcept;
    ~Screen() noexcept;

    void init(const char* title, int xpos, int ypos, int wigth, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    void displayBase() noexcept;
    void displayLine() noexcept;
    void createBase() noexcept;
    inline void startPendule() noexcept {isStart = true;}

    bool running() const {return isRunning; };
};

#endif //SDL2_TEST_SCREEN_HPP
