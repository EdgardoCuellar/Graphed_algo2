#include "Screen.hpp"

using namespace std;

Screen::Screen() noexcept = default;

Screen::~Screen() noexcept = default;

void Screen::init(const char *title, int xpos, int ypos, int wigth, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout << "All is init" << endl;

        window = SDL_CreateWindow(title, xpos, ypos, wigth, height, flags);
        if (window){
            cout << "Window created" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255);
            cout << "Renderer create" << endl;
        }
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        isRunning = true;
    } else{
        isRunning = false;
    }
    createBase();
    cout << "Size : " << static_cast<int>(WITDH/NB_LINE) / SIZE << endl;
}

void Screen::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    startPendule();
                    break;
            }

    }
}
void Screen::update(){
    if (isStart && counter <= WITDH){
        for (int i = 0; i < SPEED; ++i) {
            auto x = static_cast<float>(counter-static_cast<int>(WITDH/2)) / SIZE;
            /**********FORMULE************/
            float y = -( 1/x );
            /****************************/
            lines.push_back(y*SIZE+static_cast<float>(HEIGHT)/2);
            counter++;
        }
    }
}

void Screen::render(){
    // Background
    SDL_SetRenderDrawColor(renderer, COLORS[0][0], COLORS[0][1], COLORS[0][2], 255);
    SDL_RenderClear(renderer);
    displayBase();
    // Display all point
    if (isStart)
        displayLine();
    SDL_RenderPresent(renderer);
}

void Screen::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "All clean up" << endl;
}

void Screen::createBase() noexcept {
    // HORIZONTALE
    for (int i = 1; i < NB_LINE; ++i) {
        if (i == NB_LINE/2)
            base.push_back(Line(0, i*(WITDH/NB_LINE), WITDH, i*(WITDH/NB_LINE), true));
        else
            base.push_back(Line(0, i*(WITDH/NB_LINE), WITDH, i*(WITDH/NB_LINE), false));
    }
    // VERTICALE
    for (int i = 1; i < NB_LINE; ++i) {
        if (i == NB_LINE/2)
            base.push_back(Line(i*(HEIGHT/NB_LINE), 0, i*(HEIGHT/NB_LINE), HEIGHT, true));
        else
            base.push_back(Line(i*(HEIGHT/NB_LINE), 0, i*(HEIGHT/NB_LINE), HEIGHT, false));
    }
}

void Screen::displayBase() noexcept {
    for (auto & i : base) {
        if (i.isCenter())
            SDL_SetRenderDrawColor(renderer, COLORS[2][0], COLORS[2][1], COLORS[2][2], 200);
        else
            SDL_SetRenderDrawColor(renderer, COLORS[1][0], COLORS[1][1], COLORS[1][2], 50);
        SDL_RenderDrawLine(renderer, i.getPosX(), i.getPosY(), i.getVecX(), i.getVecY());
    }
}

void Screen::displayLine() noexcept {
    SDL_SetRenderDrawColor(renderer, COLORS[3][0], COLORS[3][1], COLORS[3][2], 255);
    for (int i = 0; i < lines.size()-1; ++i) {
        SDL_RenderDrawLine(renderer, i, static_cast<int>(lines[i]), i+1, static_cast<int>(lines[i+1]));
    }
}








