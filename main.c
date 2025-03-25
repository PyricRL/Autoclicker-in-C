#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <windows.h>
#include "SDL_ttf.h"
#include "button.h"

//pacman -S mingw-w64-x86_64-SDL2_ttf
//gcc main.c -lSDL2 -lSDL2main -lSDL2_ttf -o main
//gcc main.c button.c -IC:/msys64/mingw64/include/SDL2 -LC:/msys64/mingw64/lib -lSDL2 -lSDL2main -lSDL2_ttf -o main
//./main

INPUT inputs[2];

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;

Button btn;

int running = 1;

void createInputs() {
    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
}

void keyPress() {
    if (GetAsyncKeyState('F') & 0x8000) {
        running = 0;
    }
}

void click(int delay) {
    SendInput(2, inputs, sizeof(INPUT));
    Sleep(delay);
}

void renderScreen() {
    window = SDL_CreateWindow("Hello, World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 500, SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        printf("Failed to create window: %s\n", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }
}

void renderItemsToScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    renderButton(&btn, renderer);
    SDL_RenderPresent(renderer);
}

int main(int argc, char** args) {
    printf("Starting main...\n");
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    } else {
        printf("SDL_Init success\n");
    }
    TTF_Init();

    renderScreen();
    //Sleep(5000);

    btn = createButton(100, 100, 200, 50, 1, 
        (SDL_Color){255, 0, 0, 255}, 
        (SDL_Color){100, 0, 0, 255}, 
        (SDL_Color){0, 0, 0, 255},
        "Hi");

    while (running) {
        renderItemsToScreen();
        createInputs();
        //click(0);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
        keyPress();
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}