//
// Created by xraw on 22.05.2022.
//

#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <iostream>

class GUI {

public:
    const int win_w;
    const int win_h;

    GUI(int width, int height);
    ~GUI();

    void clear();
    void draw_square(int x, int y, int a, Uint8 r, Uint8 g, Uint8 b);
    void render_present();

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    void init();

};

#endif //GUI_H
