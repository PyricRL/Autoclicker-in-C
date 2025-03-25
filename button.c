#define SDL_MAIN_HANDLED

#include "button.h"
//#include "SDL_ttf.h"
#include <SDL2/SDL.h>
#include <stdio.h>

Button createButton(int x, int y, int width, int height, 
    int pressed, 
    SDL_Color baseColor, SDL_Color hoverColor, SDL_Color borderColor, char text[]) {
        TTF_Font *Font = TTF_OpenFont("font.ttf", 24);
        printf("Button Created...\n");
        Button btn = {x, y, width, height, pressed, baseColor, hoverColor, borderColor, text};
        return btn;
}

void renderButton(Button* btn, SDL_Renderer *renderer) {
    SDL_Rect rect = {btn->y, btn->x, btn->width, btn->height};
    SDL_SetRenderDrawColor(renderer, btn->baseColor.r, btn->baseColor.g, btn->baseColor.b, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Font, btn->text, (SDL_Color){255, 255, 255, 255});
    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect messageRect = {(btn->x + btn->width) / 2, (btn->y + btn->width) / 2, btn->width, btn->height};
}