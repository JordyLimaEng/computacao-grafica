#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"

//Analog joystick dead zone
const int JOYSTICK_DEAD_ZONE = 8000;
//Game Controller 1 handler
SDL_Joystick* gGameController = NULL;

using namespace std;
int main(int argc, char ** argv)
{
    int quit = 0, hor = 0, ver = 0;
    SDL_Event event;

    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK ) < 0)
    {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        return 0;
    }

    ///SDL_Window * window = SDL_CreateWindow("gamepad", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = 1;
            break;
        case SDL_JOYAXISMOTION:  /* Handle Joystick Motion */
            if ( ( event.jaxis.value < -3200 ) || (event.jaxis.value > 3200 ) ){
              if( event.jaxis.axis == 0){
                /* Left-right movement code goes here */
                hor++;
                cout << hor << "- horizontal" << endl;
              }if( event.jaxis.axis == 1){
               /* Up-Down movement code goes here */
                ver++;
                cout << ver << " - vertical" << endl;
              }
              cout << SDL_JoystickNameForIndex(0) << " - > Testando..." << endl;
            }
            break;
        }
    //printf("%i joysticks were found.\n\n", SDL_NumJoysticks() );
    //printf("The names of the joysticks are:\n");

    //for( int i=0; i < SDL_NumJoysticks(); i++ ){
    //    printf("    %s\n", SDL_JoystickNameForIndex(i));
    // }
    SDL_Joystick *joystick;
    SDL_JoystickEventState(SDL_ENABLE);
    joystick = SDL_JoystickOpen(0);

    }
    ///SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
