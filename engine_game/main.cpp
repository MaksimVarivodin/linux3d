#include <iostream>
#include <SDL2/SDL.h>
#include "point.hpp"
#include "direction.hpp"
#include "matrix.hpp"

int main()
{
    using namespace el;
    auto A(point<float, 4>({1, 2, 3, 4}));
    auto B(point<float, 3>({4, 5, 6}));
    auto C(point<float, 4>({7, 8, 9, 10}));
    matrix<float, 3, 3> mat;
    try
    {
        direction<float, 2> d(array<float, 2>({2, 4}));
        std::cout << "D.x " << d[axis::x]
            << " D.y " << d[axis::y] << std::endl;
        std::cout << "D length: " << d.length() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Hello SDL", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) {
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
    SDL_RenderDrawLine(ren, 100, 100, 500, 400);

    // Present the renderer
    SDL_RenderPresent(ren);

    // Event loop
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}