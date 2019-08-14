#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
  //Inicialização
bool running = true;

//Gameloop
while(running)
{
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
    }
  }
  //Atualizações gerais devem vir aqui
  SDL_Window * window = SDL_CreateWindow("Hi mundo!", 100, 100, 800, 600, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  ///Rendering
  SDL_SetRenderDrawColor(renderer, 127, 0, 127, 255);
  SDL_Rect rect = {350, 250, 100, 100};
  SDL_RenderFillRect(renderer, &rect);
  SDL_RenderPresent(renderer);

  //Não vá tão rápido!
  SDL_Delay(10); //Isso causa algo como 60 quadros por segundo.
}
}
