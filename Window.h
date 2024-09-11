#pragma once
#include <SDL.h>
class Window
{
public:
    SDL_Window* SDLWindow;
    SDL_Renderer* SDLRenderer;

    Window()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDLWindow = SDL_CreateWindow("MyCalculator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,600, 600, 0);
    }

    ~Window() // 소멸자
    {
        SDL_DestroyWindow(SDLWindow);
    }

    void Render()
    {
        SDL_FillRect(GetSurface(), nullptr,SDL_MapRGB(GetSurface()->format, 30, 30, 30)); // Window Surface의 표면전체를, RGB를 SDL이 이해할 수 있는 format으로 변환, 505050으로 set
    }

    void Update()
    {
        SDL_UpdateWindowSurface(SDLWindow); // Surface에 그린 내용을 화면에 반영.
    }

    SDL_Surface* GetSurface()
    {
        return SDL_GetWindowSurface(SDLWindow); //Window Surface를 return해주는 함수
    }

};