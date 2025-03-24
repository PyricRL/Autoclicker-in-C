#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

//gcc main.c -lSDL2 -lSDL2main -o main
//./main

int main(int argc, char** args) {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window * window = SDL_CreateWindow("Hello, World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 500, SDL_WINDOW_RESIZABLE);

    SDL_Delay(5000);

    if ( !window ) {
        printf("Error! Failed to create window: %d", SDL_GetError());
    }

    return 0;
}