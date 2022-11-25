#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Renderer * screen=NULL;

typedef unsigned char uint8;


void setColor(uint8 r, uint8 g, uint8 b)
{
	SDL_SetRenderDrawColor(screen,r,g,b,SDL_ALPHA_OPAQUE);
}

void setBackColor(uint8 r, uint8 g, uint8 b)
{
	setColor(r,g,b);
	SDL_RenderClear(screen);
}

int main(int argc, char *argv[]) {
  SDL_Window *window=NULL;

  SDL_Init(SDL_INIT_VIDEO);

  //CRIAR A JANELA
  window = SDL_CreateWindow("Jogo da Velha", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED ,800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  setBackColor(133,192,233);

  //cria o objeto
  setColor(255,0,0);
  SDL_Rect box;
	box.x=400;
	box.y=300;
	box.w=20;
	box.h=20;
	SDL_RenderFillRect(screen,&box);

  //cria o objeto
  setColor(0,0,0);
  SDL_Rect box2;
	box2.x=300;
	box2.y=200;
	box2.w=20;
	box2.h=20;
	SDL_RenderFillRect(screen,&box2);

  //cria o objeto
  setColor(255,0,0);
  SDL_Rect box3;
	box3.x=500;
	box3.y=400;
	box3.w=20;
	box3.h=20;
	SDL_RenderFillRect(screen,&box3);

  int exit = 1;
  while (exit)
  {
    int x,y;
    int selecionado;
    int b = 255;
    int gx;
    int gy;

    SDL_Event ev;
    while(SDL_PollEvent(&ev))
    {
      switch(ev.type)
      {
        case SDL_QUIT:
                exit = 0;
                break;

        // MOVE QUADRADO VERMELHO
        case SDL_KEYDOWN:
					switch(ev.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							exit = 0;
							break;
						case SDLK_LEFT:
              if(box.x > 10) box.x-=30;
							break;
						case SDLK_RIGHT:
							if(box.x < 790) box.x+=30;
							break;
						case SDLK_UP:
							if(box.y > 25) box.y-=30;
							break;
						case SDLK_DOWN:
							if(box.y < 570) box.y+=30;
              break;

            //MOVE QUADRADO PRETOA
            case SDLK_a:
              if(box2.x > 10) box2.x-=30;
							break;
              printf("A clicado/n");
            case SDLK_d:
              if(box2.x < 780) box2.x+=30;
							break;
              printf("d/n");
            case SDLK_w:
              if(box2.y > 25) box2.y-=30;
							break;
              printf("W/n");
            case SDLK_s:
              if(box2.y < 570) box2.y+=30;
              break;
              printf("S/n");
					}
        break;
        case SDL_MOUSEBUTTONDOWN:
            x=ev.button.x;
            y=ev.button.y;
            if(x > box.x && x < box.x+box.w && y > box.y && y < box.y+box.h) {
              selecionado = 1;
            }
            else selecionado = 0;
            break;
        case SDL_MOUSEBUTTONUP:
            x=ev.button.x;
            y=ev.button.y;
            if(ev.button.button==SDL_BUTTON_LEFT) {
                if(selecionado == 1){
                    box.x = x;
                    box.y = y;
                }
            }
        break;
      }
      break;
    }
    setBackColor(133,193,233); //coloca a cor de fundo em azul novamente
		setColor(255,0,0); //coloca a cor do quadradro em vermelho
    SDL_RenderFillRect(screen,&box); //coloca o objeto na screen
    setColor(0,0,0);
    SDL_RenderFillRect(screen,&box2);
    setColor(255,0,0);
    SDL_RenderFillRect(screen,&box3);
    SDL_RenderPresent(screen); //renderiza a screen
  }
  
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}