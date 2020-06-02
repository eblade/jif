#ifndef JIF_VIEW
#define JIF_VIEW

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SOURCE_WIDTH 16
#define SOURCE_HEIGHT 16
#define DESTINATION_WIDTH 16
#define DESTINATION_HEIGHT 24

namespace JIF {
    class View {
        public:
            View(SDL_Renderer* renderer, SDL_Texture* texture);
            void setPosition(const unsigned int x, const unsigned int y);
            void printString(const char* str, int16_t cursor);
        private:
            void chooseType(const char c, bool invert);
            SDL_Renderer* renderer;
            SDL_Texture* texture;
            SDL_Rect source = {0, 0, SOURCE_WIDTH, SOURCE_HEIGHT};
            SDL_Rect destination = {0, 0, DESTINATION_WIDTH, DESTINATION_HEIGHT};
    };

    View::View(SDL_Renderer* renderer, SDL_Texture* texture) {
        this->renderer = renderer;
        this->texture = texture;
    }

    void View::setPosition(const unsigned int x, const unsigned int y) {
        destination.x = x * DESTINATION_WIDTH;
        destination.y = y * DESTINATION_HEIGHT;
    }

    void View::chooseType(const char c, bool invert) {
        char x = 0, y = 0;
        switch (c) {
            //'Â£': Character({ image: CharacterMap, x: 12, y: 1 }),
            case '@':  x =  0; break;
            case 'a':  x =  1; break;
            case 'b':  x =  2; break;
            case 'c':  x =  3; break;
            case 'd':  x =  4; break;
            case 'e':  x =  5; break;
            case 'f':  x =  6; break;
            case 'g':  x =  7; break;
            case 'h':  x =  8; break;
            case 'i':  x =  9; break;
            case 'j':  x = 10; break;
            case 'k':  x = 11; break;
            case 'l':  x = 12; break;
            case 'm':  x = 13; break;
            case 'n':  x = 14; break;
            case 'o':  x = 15; break;

            case 'p':  x =  0; y = 1; break;
            case 'q':  x =  1; y = 1; break;
            case 'r':  x =  2; y = 1; break;
            case 's':  x =  3; y = 1; break;
            case 't':  x =  4; y = 1; break;
            case 'u':  x =  5; y = 1; break;
            case 'v':  x =  6; y = 1; break;
            case 'w':  x =  7; y = 1; break;
            case 'x':  x =  8; y = 1; break;
            case 'y':  x =  9; y = 1; break;
            case 'z':  x = 10; y = 1; break;
            case '[':  x = 11; y = 1; break;
            case ']':  x = 13; y = 1; break;

            case ' ':  x =  0; y = 2; break;
            case '!':  x =  1; y = 2; break;
            case '"':  x =  2; y = 2; break;
            case '#':  x =  3; y = 2; break;
            case '$':  x =  4; y = 2; break;
            case '%':  x =  5; y = 2; break;
            case '&':  x =  6; y = 2; break;
            case '`':  x =  7; y = 2; break;
            case '\'': x =  7; y = 2; break;
            case '(':  x =  8; y = 2; break;
            case ')':  x =  9; y = 2; break;
            case '*':  x = 10; y = 2; break;
            case '+':  x = 11; y = 2; break;
            case ',':  x = 12; y = 2; break;
            case '-':  x = 13; y = 2; break;
            case '.':  x = 14; y = 2; break;
            case '/':  x = 15; y = 2; break;

            case '0':  x =  0; y = 3; break;
            case '1':  x =  1; y = 3; break;
            case '2':  x =  2; y = 3; break;
            case '3':  x =  3; y = 3; break;
            case '4':  x =  4; y = 3; break;
            case '5':  x =  5; y = 3; break;
            case '6':  x =  6; y = 3; break;
            case '7':  x =  7; y = 3; break;
            case '8':  x =  8; y = 3; break;
            case '9':  x =  9; y = 3; break;
            case ':':  x = 10; y = 3; break;
            case ';':  x = 11; y = 3; break;
            case '<':  x = 12; y = 3; break;
            case '=':  x = 13; y = 3; break;
            case '>':  x = 14; y = 3; break;
            case '?':  x = 15; y = 3; break;

            case 'A':  x =  1; y = 4; break;
            case 'B':  x =  2; y = 4; break;
            case 'C':  x =  3; y = 4; break;
            case 'D':  x =  4; y = 4; break;
            case 'E':  x =  5; y = 4; break;
            case 'F':  x =  6; y = 4; break;
            case 'G':  x =  7; y = 4; break;
            case 'H':  x =  8; y = 4; break;
            case 'I':  x =  9; y = 4; break;
            case 'J':  x = 10; y = 4; break;
            case 'K':  x = 11; y = 4; break;
            case 'L':  x = 12; y = 4; break;
            case 'M':  x = 13; y = 4; break;
            case 'N':  x = 14; y = 4; break;
            case 'O':  x = 15; y = 4; break;

            case 'P':  x =  0; y = 5; break;
            case 'Q':  x =  1; y = 5; break;
            case 'R':  x =  2; y = 5; break;
            case 'S':  x =  3; y = 5; break;
            case 'T':  x =  4; y = 5; break;
            case 'U':  x =  5; y = 5; break;
            case 'V':  x =  6; y = 5; break;
            case 'W':  x =  7; y = 5; break;
            case 'X':  x =  8; y = 5; break;
            case 'Y':  x =  9; y = 5; break;
            case 'Z':  x = 10; y = 5; break;
        };
        source.x = x << 4;
        source.y = y << 4;
        if (invert) {
            source.y += 128;
        }
    }

    void View::printString(const char* str, int16_t cursor) {
        uint16_t len = strlen(str);
        bool ext = false;
        if (cursor >= len) {
            len += 1;
            ext = true;
        }
        char c;
        int16_t i;
        for (i = 0; i < len; i++) {
            c = str[i];
            if (cursor == i) {
                if (ext) {
                    chooseType(' ', true);
                } else {
                    chooseType(c, true);
                }

                SDL_SetTextureColorMod(texture, 255, 0, 0);
            } else {
                chooseType(c, false);
                SDL_SetTextureColorMod(texture, 255, 255, 255);
            }
            SDL_RenderCopy(renderer, texture, &source, &destination);
            destination.x += DESTINATION_WIDTH;
        }
    }
}


#endif
