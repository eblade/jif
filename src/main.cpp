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
    bool run = true;

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
    buffer.Append(Line(""));
    Line* currentLine = buffer.GetLine(0);
    SDL_SetRenderDrawColor(renderer, 66, 52, 161, 255);

    while (run) {
        if (loop == 0) {
            SDL_RenderClear(renderer);
            for (unsigned int i = 0; i < 1; i++) {
                view.setPosition(0, i);
                Line* line = buffer.GetLine(i);
                view.printString(line->GetContent().c_str());
            }
            SDL_RenderPresent(renderer);
        }
        ++loop %= 50;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    run = false;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_BACKSPACE:
                            currentLine->DeleteBefore();
                            break;
                    }
                    loop = 0;
                    break;
                case SDL_TEXTINPUT:
                    currentLine->PutLast(event.text.text);
                    loop = 0;
                    break;
            }
        }
        SDL_Delay(10);
    }

    SDL_DestroyTexture(texture);
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
