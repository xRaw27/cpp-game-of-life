//
// Created by xraw on 22.05.2022.
//

#include "InputReader.h"

InputReader::InputReader(GUI * const gui, const int sides, const int spacings) :
        gui{gui}, square_sides_len{sides}, spacings{spacings}, box_size{sides + 2 * spacings},
        rows{gui->win_h / (sides + 2 * spacings)}, cols{gui->win_w / (sides + 2 * spacings)} {
    init();
}

void InputReader::init() {
    std::cout << "InputReader init: rows=" << rows << ", cols=" << cols << "\n";

    board.resize(rows, std::vector<bool>(cols));
    clear();
}

void InputReader::clear() {
    for (auto &row : board) {
        std::fill(row.begin(), row.end(), false);
    }

    gui->clear();
    gui->draw_grid(box_size, gui->win_w, gui->win_h);
    gui->render_present();
}

void InputReader::mouse_click(const Sint32 x, const Sint32 y) {
    std::cout << "Mouse click: x=" << x << ", y=" << y << "\n";

    int row = y / box_size;
    int col = x / box_size;

    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        board[row][col] = !board[row][col];
        if (board[row][col]) {
            gui->draw_square(col * box_size + spacings, row * box_size + spacings, square_sides_len, 0, 0, 0);
        }
        else {
            gui->draw_square(col * box_size + spacings, row * box_size + spacings, square_sides_len, 255, 255, 255);
        }
        gui->render_present();
    }
}

bool InputReader::read() {
    SDL_Event event;

    while (true) {
        while (SDL_WaitEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return false;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_RETURN:
                        case SDL_SCANCODE_SPACE:
                            return true;

                        case SDL_SCANCODE_ESCAPE:
                            clear();
                            break;

                        default:
                            //print();
                            break;
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    mouse_click(event.button.x, event.button.y);
                    break;
            }
        }
    }
}

void InputReader::print() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}
