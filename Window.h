#pragma once
#include <SDL.h>
class Window
{
public:
    SDL_Window* SDLWindow;

    Window() // 생성자
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDLWindow = SDL_CreateWindow("My Calculator", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 600, 600, 0);
    }

    ~Window() // 소멸자
    {
        SDL_DestroyWindow(SDLWindow);
    }

    void Render()
    {
        SDL_FillRect(GetSurface(), nullptr,SDL_MapRGB(GetSurface()->format, 50, 50, 50)); // Window Surface의 표면전체를, RGB를 SDL이 이해할 수 있는 format으로 변환, 505050으로 set
    }

    void Update()
    {
        SDL_UpdateWindowSurface(SDLWindow); // Surface에 그린 내용을 화면에 반영.
    }

    SDL_Surface* GetSurface()
    {
        return SDL_GetWindowSurface(SDLWindow); //Window Surface를 return해주는 함수
    }

    Window(const Window&) = delete; // 복사 생성자를 삭제하는 명령어, Winodw 객체는 복사될 수 없다. ex) Window window2 = window1;
    Window& operator=(const Window&) = delete; // Window 객체에 다른 Window 객체를 대입할 수 없게 만든다. ex) window2 = window1;

};