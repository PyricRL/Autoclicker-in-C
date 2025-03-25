#ifndef BUTTON_H
#define BUTTON_H
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include "SDL_ttf.h"

/* Button structure */
typedef struct {
    int x, y;
    int width, height;
    int pressed;
    SDL_Color baseColor;
    SDL_Color hoverColor;
    SDL_Color clickColor;
    char text[];
} Button;

/* Function to create and assign a button to a variable */

Button createButton(int x, int y, int width, int height, 
    int pressed, 
    SDL_Color baseColor, SDL_Color hoverColor, SDL_Color borderColor, const char *text);

/* Function to render button to screen */
void renderButton(Button *btn, SDL_Renderer *renderer);

#endif