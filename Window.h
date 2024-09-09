#pragma once
#include <SDL.h>
class Window
{
public:
    Window() // ������
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDLWindow = SDL_CreateWindow("My Calculator", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 200, 200, 0);
    }

    void Render()
    {
        SDL_FillRect(GetSurface(), nullptr,SDL_MapRGB(GetSurface()->format, 50, 50, 50));
    }

    void Update()
    {
        SDL_UpdateWindowSurface(SDLWindow);
    }

    SDL_Surface* GetSurface()
    {
        return SDL_GetWindowSurface(SDLWindow);
    }

    ~Window()
    {
        SDL_DestroyWindow(SDLWindow);
    }

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

private:
    SDL_Window* SDLWindow;
};