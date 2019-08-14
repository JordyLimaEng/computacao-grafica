#include <stdio.h>
#include "SDL2/SDL.h"

int main(int argc, char ** argv)
{
    int quit = 0;
    SDL_Event event;

    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK ) < 0)
    {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        return 0;
    }

    SDL_Window * window = SDL_CreateWindow("gamepad", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = 1;
            break;
        }
    printf("%i joysticks were found.\n\n", SDL_NumJoysticks() );
    printf("The names of the joysticks are:\n");

    for( int i=0; i < SDL_NumJoysticks(); i++ ){
        printf("    %s\n", SDL_JoystickNameForIndex(i));
     }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}