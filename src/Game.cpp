//
// Created by xraw on 22.05.2022.
//

#include "Game.h"

Game::Game(GUI *const gui, InputReader *const ir, const int margin, const int delay) :
        gui{gui}, ir{ir}, margin{margin}, delay{delay} {
    init();
}

void Game::init() {
    std::cout << "Game init\n";

    board.resize(ir->rows + 2 * margin, std::vector<bool>(ir->cols + 2 * margin));

    for (int i = 0; i < ir->rows; ++i) {
        for (int j = 0; j < ir->cols; ++j) {
            board[i + margin][j + margin] = ir->board[i][j];
        }
    }
}

bool Game::run() {
    SDL_Event event;
    int pause_result;
    int iteration = 0;

    while (true) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return false;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_RETURN:
                        case SDL_SCANCODE_SPACE:
                            pause_result = pause();
                            if (pause_result == 1) return true;
                            if (pause_result == 2) return false;
                            std::cout << "Unpause\n";
                            break;

                        case SDL_SCANCODE_ESCAPE:
                            return true;

                        default:
                            //print();
                            break;
                    }
                    break;

                default:
                    break;
            }
        }

        draw_next_step();
        gui->render_present();

        std::cout << "Current iteration: " << ++iteration << "\n";

        SDL_Delay(delay);
    }
}

void Game::draw_next_step() {
    std::vector<std::vector<bool>> new_board = board;

    int live_neighbours;
    for (int i = 1; i < ir->rows + 2 * margin - 1; ++i) {
        for (int j = 1; j < ir->cols + 2 * margin - 1; ++j) {
            live_neighbours = 0;
            live_neighbours += board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1] + board[i][j + 1];
            live_neighbours += board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i][j - 1];

            if (!board[i][j] && live_neighbours == 3) {
                new_board[i][j] = true;
                draw_square(true, j - margin, i - margin);
            } else if (board[i][j] && (live_neighbours < 2 || live_neighbours > 3)) {
                new_board[i][j] = false;
                draw_square(false, j - margin, i - margin);
            }
        }
    }

    board = std::move(new_board);
}

void Game::draw_square(const bool new_state, const int x, const int y) {
    if (x >= 0 && x < ir->cols && y >= 0 && y < ir->rows) {
        if (new_state) {
            gui->draw_square(x * ir->box_size + ir->spacings, y * ir->box_size + ir->spacings, ir->square_sides_len, 0,
                             0, 0);
        } else {
            gui->draw_square(x * ir->box_size + ir->spacings, y * ir->box_size + ir->spacings, ir->square_sides_len,
                             255, 255, 255);
        }
    }
}

int Game::pause() {
    std::cout << "Paused...\n";
    SDL_Event event;

    while (true) {
        if (SDL_WaitEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return 2;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_RETURN:
                        case SDL_SCANCODE_SPACE:
                            return 0;

                        case SDL_SCANCODE_ESCAPE:
                            return 1;

                        default:
                            break;
                    }
                    break;
            }
        }
    }
}

void Game::print() {
    for (int i = 0; i < ir->rows + 2 * margin; ++i) {
        for (int j = 0; j < ir->cols + 2 * margin; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}
