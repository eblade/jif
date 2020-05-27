#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "view.hpp"
#include "buffer.hpp"

using namespace JIF;

int main(void) {
    SDL_Event event;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    SDL_Window *window = NULL;

    unsigned int loop = 0;

    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(
        800, 800,
        0, &window, &renderer
    );
    SDL_SetWindowTitle(window, "JIF");
    IMG_Init(IMG_INIT_PNG);
    texture = IMG_LoadTexture(renderer, "c64.png");
    View view = View(renderer, texture);
    Buffer buffer = Buffer();
    buffer.Append(Line("hej"));
    buffer.Append(Line("rad 2 hejsan"));

    while (1) {
        if (loop == 0) {
            for (unsigned int i = 0; i < 2; i++) {
                view.setPosition(0, i);
                Line* line = buffer.GetLine(i);
                view.printString(line->GetContent().c_str());
            }
            SDL_RenderPresent(renderer);
        }
        ++loop %= 50;
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
        SDL_Delay(10);
    }

    SDL_DestroyTexture(texture);
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
