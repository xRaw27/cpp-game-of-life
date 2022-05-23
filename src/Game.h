//
// Created by xraw on 22.05.2022.
//

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GUI.h"
#include "InputReader.h"

class Game {

public:
    Game(GUI *gui, InputReader *ir, int margin, int delay);

    bool run();

private:
    GUI *const gui;
    InputReader *const ir;
    const int margin;
    const int delay;

    std::vector<std::vector<bool>> board;

    void init();

    void draw_next_step();

    void draw_square(bool new_state, int x, int y);

    static int pause();

    void print();
};

#endif //GAME_H
