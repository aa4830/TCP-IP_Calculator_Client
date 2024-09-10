#pragma once
#include <SDL.h>
class Window
{
public:
    SDL_Window* SDLWindow;

    Window() // ������
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDLWindow = SDL_CreateWindow("My Calculator", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 600, 600, 0);
    }

    ~Window() // �Ҹ���
    {
        SDL_DestroyWindow(SDLWindow);
    }

    void Render()
    {
        SDL_FillRect(GetSurface(), nullptr,SDL_MapRGB(GetSurface()->format, 50, 50, 50)); // Window Surface�� ǥ����ü��, RGB�� SDL�� ������ �� �ִ� format���� ��ȯ, 505050���� set
    }

    void Update()
    {
        SDL_UpdateWindowSurface(SDLWindow); // Surface�� �׸� ������ ȭ�鿡 �ݿ�.
    }

    SDL_Surface* GetSurface()
    {
        return SDL_GetWindowSurface(SDLWindow); //Window Surface�� return���ִ� �Լ�
    }

    Window(const Window&) = delete; // ���� �����ڸ� �����ϴ� ��ɾ�, Winodw ��ü�� ����� �� ����. ex) Window window2 = window1;
    Window& operator=(const Window&) = delete; // Window ��ü�� �ٸ� Window ��ü�� ������ �� ���� �����. ex) window2 = window1;

};