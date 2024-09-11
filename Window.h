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

    ~Window() // 소멸자
    {
        SDL_DestroyWindow(SDLWindow);
    }

    void Render()
    {
        SDL_FillRect(GetSurface(), nullptr,SDL_MapRGB(GetSurface()->format, 231, 231, 231)); // Window Surface의 표면전체를, RGB를 SDL이 이해할 수 있는 format으로 변환, 505050으로 set
    }
    
    void Update()
    {
        SDL_UpdateWindowSurface(SDLWindow); // Surface에 그린 내용을 화면에 반영.
    }

    SDL_Surface* GetSurface()
    {
        return SDL_GetWindowSurface(SDLWindow); //Window Surface를 return해주는 함수
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
        SDL_FillRect(GetSurface(), &ResultBoardRect, ResultBoardRectColor);  // Surface에 결과창 그리기
    }
};