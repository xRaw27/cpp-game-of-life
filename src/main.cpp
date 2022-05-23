#include "GUI.h"
#include "InputReader.h"
#include "Game.h"

#define WINDOW_WIDTH 1800
#define WINDOW_HEIGHT 900
//#define WINDOW_WIDTH 600
//#define WINDOW_HEIGHT 400
#define SPACINGS 2
#define SQUARE_SIDES_LEN 16
#define MARGIN 10
#define DELAY_MS 200


int main() {
    bool running = true;
    GUI gui(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (running) {
        InputReader input_reader(&gui, SQUARE_SIDES_LEN, SPACINGS);
        running = input_reader.read();

        if (!running) break;

        Game game(&gui, &input_reader, MARGIN, DELAY_MS);
        running = game.run();
    }

    return 0;
}
