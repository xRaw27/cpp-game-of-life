#include <SDL2/SDL.h>
//#include <iostream>
//#include <algorithm>
//#include <vector>

#include "GUI.h"
#include "InputReader.h"

#include <string_view>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400
#define SPACINGS 2
#define SQUARE_SIDES_LEN 16

template<typename T>
constexpr auto type_name() {
    std::string_view name, prefix, suffix;
#ifdef __clang__
    name = __PRETTY_FUNCTION__;
    prefix = "auto type_name() [T = ";
    suffix = "]";
#elif defined(__GNUC__)
    name = __PRETTY_FUNCTION__;
    prefix = "constexpr auto type_name() [with T = ";
    suffix = "]";
#elif defined(_MSC_VER)
    name = __FUNCSIG__;
    prefix = "auto __cdecl type_name<";
    suffix = ">(void)";
#endif
    name.remove_prefix(prefix.size());
    name.remove_suffix(suffix.size());
    return name;
}


int main() {

    bool running = true;
    GUI gui(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (running) {
        InputReader input_reader(&gui, SQUARE_SIDES_LEN, SPACINGS);

        running = input_reader.read();

        if (running) {
            std::cout << "running...";
        }
    }

    return 0;
}

//int essa() {
//
//    // returns zero on success else non-zero
//    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//        printf("Error initializing SDL: %s\n", SDL_GetError());
//    }
//    SDL_Window *win = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000, 1000, SDL_WINDOW_SHOWN);
//
//    // triggers the program that controls
//    // your graphics hardware and sets flags
//    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
//
//    // creates a renderer to render our images
//    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);
//
//    // creates a surface to load an image into the main memory
//    SDL_Surface *surface;
//
//    // please provide a path for your image
//    surface = IMG_Load("path");
//
//    // loads image to our graphics hardware memory.
//    SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, surface);
//
//    // clears main-memory
//    SDL_FreeSurface(surface);
//
//    // let us control our image position
//    // so that we can move it with our keyboard.
//    SDL_Rect dest;
//
//    // connects our texture with dest to control position
//    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
//
//    // adjust height and width of our image box.
//    dest.w /= 6;
//    dest.h /= 6;
//
//    // sets initial x-position of object
//    dest.x = (1000 - dest.w) / 2;
//
//    // sets initial y-position of object
//    dest.y = (1000 - dest.h) / 2;
//
//    // controls animation loop
//    int close = 0;
//
//    // speed of box
//    int speed = 300;
//
//    // animation loop
//    while (!close) {
//        SDL_Event event;
//
//        // Events management
//        while (SDL_PollEvent(&event)) {
//            switch (event.type) {
//
//                case SDL_QUIT:
//                    // handling of close button
//                    close = 1;
//                    break;
//
//                case SDL_KEYDOWN:
//                    // keyboard API for key pressed
//                    switch (event.key.keysym.scancode) {
//                        case SDL_SCANCODE_W:
//                        case SDL_SCANCODE_UP:
//                            dest.y -= speed / 30;
//                            break;
//                        case SDL_SCANCODE_A:
//                        case SDL_SCANCODE_LEFT:
//                            dest.x -= speed / 30;
//                            break;
//                        case SDL_SCANCODE_S:
//                        case SDL_SCANCODE_DOWN:
//                            dest.y += speed / 30;
//                            break;
//                        case SDL_SCANCODE_D:
//                        case SDL_SCANCODE_RIGHT:
//                            dest.x += speed / 30;
//                            break;
//                        default:
//                            break;
//                    }
//            }
//        }
//
//        // right boundary
//        if (dest.x + dest.w > 1000)
//            dest.x = 1000 - dest.w;
//
//        // left boundary
//        if (dest.x < 0)
//            dest.x = 0;
//
//        // bottom boundary
//        if (dest.y + dest.h > 1000)
//            dest.y = 1000 - dest.h;
//
//        // upper boundary
//        if (dest.y < 0)
//            dest.y = 0;
//
//        // clears the screen
//        SDL_RenderClear(rend);
//        SDL_RenderCopy(rend, tex, NULL, &dest);
//
//        // triggers the double buffers
//        // for multiple rendering
//        SDL_RenderPresent(rend);
//
//        // calculates to 60 fps
//        SDL_Delay(1000 / 60);
//    }
//
//    // destroy texture
//    SDL_DestroyTexture(tex);
//
//    // destroy renderer
//    SDL_DestroyRenderer(rend);
//
//    // destroy window
//    SDL_DestroyWindow(win);
//
//    // close SDL
//    SDL_Quit();
//
//    return 0;
//}