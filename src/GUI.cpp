//
// Created by xraw on 22.05.2022.
//

#include "GUI.h"

GUI::GUI(const int width, const int height) : win_w{width}, win_h{height} {
    std::cout << "GUI constructor\n";
    init();
}

void GUI::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_w, win_h,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr){
        fprintf(stderr, "Couldn't create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

GUI::~GUI() {
    std::cout << "GUI destructor\n";
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GUI::clear() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void GUI::draw_square(const int x, const int y, const int a, const Uint8 r, const Uint8 g, const Uint8 b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect square = {x, y, a, a};
    SDL_RenderFillRect(renderer, &square);
}

void GUI::draw_grid(const int box_size, const int width, const int height) {
    SDL_SetRenderDrawColor(renderer, 240, 240, 240, 255);
    for (int y = -1; y < height; y += box_size) {
        SDL_RenderDrawLine(renderer, 0, y, width, y);
        SDL_RenderDrawLine(renderer, 0, y + 1, width, y + 1);
    }
    for (int x = -1; x < width; x += box_size) {
        SDL_RenderDrawLine(renderer, x, 0, x, height);
        SDL_RenderDrawLine(renderer, x + 1, 0, x + 1, height);
    }
}

void GUI::render_present() {
    SDL_RenderPresent(renderer);
}
