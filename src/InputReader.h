//
// Created by xraw on 22.05.2022.
//

#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <vector>
#include "GUI.h"

class InputReader {
    friend class Game;

public:
    InputReader(GUI *gui, int sides, int spacings);

    bool read();

private:
    GUI *const gui;
    const int square_sides_len;
    const int spacings;
    const int box_size;
    const int rows;
    const int cols;

    std::vector<std::vector<bool>> board;

    void init();

    void clear();

    void mouse_click(Sint32 x, Sint32 y);

    void print();
};


#endif //INPUTREADER_H
