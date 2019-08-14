#include <SDL2/SDL.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  //Inicialização
struct Ball
{
  SDL_Rect bbox = {0, 0, 100, 100};
  SDL_Point vel = {1, 1};
};
Ball ball;

bool running = true;
//Gameloop
int x=0;

while(running){
  ///Logica
  //Detecção de Evento
  SDL_Event event;
  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT: //Caso saia
        running = false;
        break;
      case SDL_MOUSEBUTTONDOWN:
    {
        SDL_Point mousePos = {event.button.x, event.button.y};
          if(event.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&mousePos, 1, &ball.bbox, nullptr) )
          {
            SDL_Log("CLICK");
            Sint16 absVel = abs(ball.vel.x);
            if(absVel < 32)
            {
              ball.vel.y = ball.vel.x = absVel + 1;
              if(rand() %2 == 0)
                ball.vel.x = - ball.vel.x;
              if(rand() %2 == 0)
                ball.vel.y = - ball.vel.y;
            }
          }
          break;
    }
      break;
        }
  }
  //Atualizações gerais devem vir aqui
  ///Rendering
  SDL_Window * window = SDL_CreateWindow("OPA", 100, 100, 800, 600, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(renderer, 127, 0, 127, 255);
  SDL_Rect rect = {350, 250, 100, 100};
  SDL_RenderFillRect(renderer, &ball.bbox);
  ball.bbox.x += ball.vel.x;
  ball.bbox.y += ball.vel.y;
  if(ball.bbox.x < 0 || ball.bbox.x + ball.bbox.w >= 800)
  ball.vel.x = -ball.vel.x;

  if(ball.bbox.y < 0 || ball.bbox.y + ball.bbox.h >= 600)
  ball.vel.y = -ball.vel.y;
  SDL_RenderPresent(renderer);

  //Não vá tão rápido!
  SDL_Delay(10); //Isso causa algo como 60 quadros por segundo.
}
}
