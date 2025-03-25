#define SDL_MAIN_HANDLED

#include "button.h"
#include "SDL_ttf.h"
#include <SDL2/SDL.h>
#include <stdio.h>

Button createButton(int x, int y, int width, int height, 
    char *text, int pressed, 
    SDL_Color baseColor, SDL_Color hoverColor, SDL_Color borderColor, 
    SDL_Color fontColor, TTF_Font *font) {
        printf("Button Created");
        Button btn = {x, y, width, height, text, pressed, baseColor, hoverColor, borderColor, fontColor, font};
        return btn;
}

void renderButton(Button* btn, SDL_Renderer *renderer) {
    SDL_Rect rect = {btn->y, btn->x, btn->width, btn->height};
    SDL_SetRenderDrawColor(renderer, btn->baseColor.r, btn->baseColor.g, btn->baseColor.b, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_Surface *textSurface = TTF_RenderText_Solid(btn->font, btn->text, btn->fontColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
}