#include <stdlib.h>

#include <SDL2/SDL.h>

int main(void) {
    SDL_Event event;
    SDL_Renderer *renderer = NULL;
    SDL_Window *window = NULL;

    bool run = true;

    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(
        800, 800,
        0, &window, &renderer
    );
    SDL_SetWindowTitle(window, "JIF");
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);

    while (run) {

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    run = false;
                    break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
