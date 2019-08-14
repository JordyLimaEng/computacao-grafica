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

    int number_of_buttons = SDL_JoystickNumButtons(gGameController);
    cout << SDL_JoystickNameForIndex(0) <<"Conectado e possui " <<number_of_buttons << " - Botoes" << endl;
    ///SDL_Window * window = SDL_CreateWindow("gamepad", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type){
        case SDL_QUIT:
            quit = 1;
        break;

        case SDL_JOYAXISMOTION:  /* Recebe movimento nos analógicos */
            if ( ( event.jaxis.value < -3200 ) || (event.jaxis.value > 3200 ) ){
              if( event.jaxis.axis == 0){
                hor++;
                cout << hor << "- horizontal" << endl;
              }if( event.jaxis.axis == 1){
                ver++;
                cout << ver << " - vertical" << endl;
              }
            }
            if (( event.jaxis.value < -3200 ) || (event.jaxis.value > 3200 )){
                if( event.caxis.value == 0){
                hor++;
                cout << hor << "- horizontal" << endl;
              }if( event.caxis.value == 1){
                ver++;
                cout << ver << " - vertical" << endl;
              }
            }
        break;

        case SDL_JOYBUTTONDOWN:  /* Recebe key_press dos botões */
             int bt = event.jbutton.button;
            if(bt == 0){
                cout << "BOTAO 1" <<endl;
            }else if(bt == 1){
                cout << "BOTAO 2" <<endl;
            }else if(bt == 2){
                cout << "BOTAO 3" <<endl;
            }else if(bt == 3){
                cout << "BOTAO 4" <<endl;
            }else if(bt == 4){
                cout << "BOTAO L1" <<endl;
            }else if(bt == 5){
                cout << "BOTAO R1" <<endl;
            }else if(bt == 6){
                cout << "BOTAO L2" <<endl;
            }else if(bt == 7){
                cout << "BOTAO R2" <<endl;
            }else if(bt == 8){
                cout << "SELECT" <<endl;
            }else if(bt == 9){
                cout << "START" <<endl;
            }else if(bt == 10){
                cout << "L3" <<endl;
            }else if(bt == 11){
                cout << "R3" <<endl;
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

/*
GAMEPAD BOYU - KEYMAP
    BOTAO  1 - 0
    BOTAO  2 - 1
    BOTAO  3 - 2
    BOTAO  4 - 3
    BOTAO L1 - 4
    BOTAO R1 - 5
    BOTAO L2 - 6
    BOTAO R2 - 7
    BOTAO SELECT - 8
    BOTAO START - 9
    BOTAO L3 - 10
    BOTAO R3 - 11
    SETA UP - nA
    SETA DW - nA
    SETA LF - nA
    SETA RT - nA
*/
