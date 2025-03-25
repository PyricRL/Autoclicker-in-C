#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <windows.h>
#include "button.h"
#include "SDL_ttf.h"

Button btn;

int main() {
    TTF_Init();
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }
    
    SDL_Window *window = SDL_CreateWindow("Hello, World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 500, SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        printf("Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    TTF_Font *Sans = TTF_OpenFont("font.ttf", 24);
    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, "Hello, World!", (SDL_Color){255, 255, 255, 255});
    SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 0;  //controls the rect's x coordinate 
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 100;

    btn = createButton(100, 100, 200, 50, "Click Me", 1, 
        (SDL_Color){255, 0, 0, 255}, 
        (SDL_Color){100, 0, 0, 255}, 
        (SDL_Color){0, 0, 0, 255});

    while (1) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        renderButton(&btn, renderer);
        SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}