#include <iostream>
#include <SDL2/SDL.h>
#include "point.hpp"
#include "direction.hpp"
#include "matrix.hpp"

int main()
{
    using namespace el;


    /*if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Hello SDL", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // Set the draw color to white
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);

    // Clear the window
    SDL_RenderClear(ren);

    // Set the draw color to red
    SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);

    // Draw a line
    SDL_RenderDrawLine(ren, 320, 478, 320, 1);
    SDL_RenderDrawLine(ren, 0, 240, 640, 240);
    SDL_RenderDrawPointF(ren, 320, 240);

    // Present the renderer
    SDL_RenderPresent(ren);

    // Event loop
    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();*/

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
