#ifndef BUTTON_H
#define BUTTON_H
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include "SDL_ttf.h"

/* Button structure */
typedef struct {
    int x, y;
    int width, height;
    char *text;
    int pressed;
    SDL_Color baseColor;
    SDL_Color hoverColor;
    SDL_Color clickColor;
    SDL_Color fontColor;
    TTF_Font *font;
} Button;

/* Function to create and assign a button to a variable */

Button createButton(int x, int y, int width, int height, 
    char *text, int pressed, 
    SDL_Color baseColor, SDL_Color hoverColor, SDL_Color borderColor, 
    SDL_Color fontColor, TTF_Font *font);

/* Function to render button to screen */
void renderButton(Button *btn, SDL_Renderer *renderer);

#endif