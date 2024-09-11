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

    ~Window() // �Ҹ���
    {
        SDL_DestroyWindow(SDLWindow);
    }

    void Render()
    {
        SDL_FillRect(GetSurface(), nullptr,SDL_MapRGB(GetSurface()->format, 30, 30, 30)); // Window Surface�� ǥ����ü��, RGB�� SDL�� ������ �� �ִ� format���� ��ȯ, 505050���� set
    }

    void Update()
    {
        SDL_UpdateWindowSurface(SDLWindow); // Surface�� �׸� ������ ȭ�鿡 �ݿ�.
    }

    SDL_Surface* GetSurface()
    {
        return SDL_GetWindowSurface(SDLWindow); //Window Surface�� return���ִ� �Լ�
    }

};