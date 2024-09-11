#pragma once
#include <SDL.h>
#include "Text.h"
class Window
{
public:
    SDL_Window* SDLWindow;
    SDL_Renderer* SDLRenderer;
    SDL_Rect ResultBoardRect;
    Text MyText;

    Window()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDLWindow = SDL_CreateWindow("MyCalculator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,400, 600, 0);

    }

    ~Window() // �Ҹ���
    {
        SDL_DestroyWindow(SDLWindow);
    }

    void Render()
    {
        SDL_FillRect(GetSurface(), nullptr,SDL_MapRGB(GetSurface()->format, 231, 231, 231)); // Window Surface�� ǥ����ü��, RGB�� SDL�� ������ �� �ִ� format���� ��ȯ, 505050���� set
    }
    
    void Update()
    {
        SDL_UpdateWindowSurface(SDLWindow); // Surface�� �׸� ������ ȭ�鿡 �ݿ�.
    }

    SDL_Surface* GetSurface()
    {
        return SDL_GetWindowSurface(SDLWindow); //Window Surface�� return���ִ� �Լ�
    }

    void Draw1TextOnButton()
    {
        if (MyText.Number1TextSurface != nullptr)
        {
            SDL_FreeSurface(MyText.Number1TextSurface);
        }
        MyText.Number1TextSurface = TTF_RenderText_Solid(MyText.Font, "1", MyText.NumberTextColor);
        if (MyText.Number1TextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.Number1TextSurface, nullptr, GetSurface(), &MyText.Number1TextPosition);
        }
    }
    void DrawResultBoard()
    {
        ResultBoardRect.x = 30;
        ResultBoardRect.y = 30;
        ResultBoardRect.w = 340;
        ResultBoardRect.h = 120;
        Uint32 ResultBoardRectColor = SDL_MapRGB(MyWindow.GetSurface()->format, 240, 240, 240);
        SDL_FillRect(GetSurface(), &ResultBoardRect, ResultBoardRectColor);  // Surface�� ���â �׸���
    }
};