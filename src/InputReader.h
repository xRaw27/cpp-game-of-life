//
// Created by xraw on 22.05.2022.
//

#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <vector>
#include "GUI.h"

class InputReader {

public:
    InputReader(GUI *gui, int sides, int spacings);

    bool read();

private:
    GUI *gui;
    const int square_sides_len;
    const int spacings;
    const int box_size;
    const int rows;
    const int cols;

    std::vector<std::vector<bool>> board;

    void init();
    void clear();
    void print();
    void mouse_click(Sint32 x, Sint32 y);
};


#endif //INPUTREADER_H
