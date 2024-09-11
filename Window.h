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
    void Draw2TextOnButton()
    {
        if (MyText.Number2TextSurface != nullptr)
        {
            SDL_FreeSurface(MyText.Number2TextSurface);
        }
        MyText.Number2TextSurface = TTF_RenderText_Solid(MyText.Font, "2", MyText.NumberTextColor);
        if (MyText.Number2TextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.Number2TextSurface, nullptr, GetSurface(), &MyText.Number2TextPosition);
        }
    }
    void Draw3TextOnButton()
    {
        if (MyText.Number3TextSurface != nullptr)
        {
            SDL_FreeSurface(MyText.Number3TextSurface);
        }
        MyText.Number3TextSurface = TTF_RenderText_Solid(MyText.Font, "3", MyText.NumberTextColor);
        if (MyText.Number3TextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.Number3TextSurface, nullptr, GetSurface(), &MyText.Number3TextPosition);
        }
    }
    void Draw4TextOnButton()
    {
        if (MyText.Number4TextSurface != nullptr)
        {
            SDL_FreeSurface(MyText.Number4TextSurface);
        }
        MyText.Number4TextSurface = TTF_RenderText_Solid(MyText.Font, "4", MyText.NumberTextColor);
        if (MyText.Number4TextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.Number4TextSurface, nullptr, GetSurface(), &MyText.Number4TextPosition);
        }
    }
    void Draw5TextOnButton()
    {
        if (MyText.Number5TextSurface != nullptr)
        {
            SDL_FreeSurface(MyText.Number5TextSurface);
        }
        MyText.Number5TextSurface = TTF_RenderText_Solid(MyText.Font, "5", MyText.NumberTextColor);
        if (MyText.Number5TextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.Number5TextSurface, nullptr, GetSurface(), &MyText.Number5TextPosition);
        }
    }
    void Draw6TextOnButton()
    {
        if (MyText.Number6TextSurface != nullptr)
        {
            SDL_FreeSurface(MyText.Number6TextSurface);
        }
        MyText.Number6TextSurface = TTF_RenderText_Solid(MyText.Font, "6", MyText.NumberTextColor);
        if (MyText.Number6TextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.Number6TextSurface, nullptr, GetSurface(), &MyText.Number6TextPosition);
        }
    }
    void Draw7TextOnButton()
    {
        if (MyText.Number7TextSurface != nullptr)
        {
            SDL_FreeSurface(MyText.Number7TextSurface);
        }
        MyText.Number7TextSurface = TTF_RenderText_Solid(MyText.Font, "7", MyText.NumberTextColor);
        if (MyText.Number7TextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.Number7TextSurface, nullptr, GetSurface(), &MyText.Number7TextPosition);
        }
    }
    void Draw8TextOnButton()
    {
        if (MyText.Number8TextSurface != nullptr)
        {
            SDL_FreeSurface(MyText.Number8TextSurface);
        }
        MyText.Number8TextSurface = TTF_RenderText_Solid(MyText.Font, "8", MyText.NumberTextColor);
        if (MyText.Number8TextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.Number8TextSurface, nullptr, GetSurface(), &MyText.Number8TextPosition);
        }
    }
    void Draw9TextOnButton()
    {
        if (MyText.Number9TextSurface != nullptr)
        {
            SDL_FreeSurface(MyText.Number9TextSurface);
        }
        MyText.Number9TextSurface = TTF_RenderText_Solid(MyText.Font, "9", MyText.NumberTextColor);
        if (MyText.Number9TextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.Number9TextSurface, nullptr, GetSurface(), &MyText.Number9TextPosition);
        }
    }
    void Draw0TextOnButton()
    {
        if (MyText.Number0TextSurface != nullptr)
        {
            SDL_FreeSurface(MyText.Number0TextSurface);
        }
        MyText.Number0TextSurface = TTF_RenderText_Solid(MyText.Font, "0", MyText.NumberTextColor);
        if (MyText.Number0TextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.Number0TextSurface, nullptr, GetSurface(), &MyText.Number0TextPosition);
        }
    }
    void DrawDivideOnButton()
    {
        if (MyText.DivideSurface != nullptr)
        {
            SDL_FreeSurface(MyText.DivideSurface);
        }
        MyText.DivideSurface = TTF_RenderText_Solid(MyText.Font, "/", MyText.NumberTextColor);
        if (MyText.DivideSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.DivideSurface, nullptr, GetSurface(), &MyText.DividePosition);
        }
    }
    void DrawMinusOnButton()
    {
        if (MyText.MinusSurface != nullptr)
        {
            SDL_FreeSurface(MyText.MinusSurface);
        }
        MyText.MinusSurface = TTF_RenderText_Solid(MyText.Font, "-", MyText.NumberTextColor);
        if (MyText.MinusSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.MinusSurface, nullptr, GetSurface(), &MyText.MinusPosition);
        }
    }
    void DrawAddOnButton()
    {
        if (MyText.AddSurface != nullptr)
        {
            SDL_FreeSurface(MyText.AddSurface);
        }
        MyText.AddSurface = TTF_RenderText_Solid(MyText.Font, "+", MyText.NumberTextColor);
        if (MyText.AddSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.AddSurface, nullptr, GetSurface(), &MyText.AddPosition);
        }
    }
    void DrawMultiplyOnButton()
    {
        if (MyText.MultiplySurface != nullptr)
        {
            SDL_FreeSurface(MyText.MultiplySurface);
        }
        MyText.MultiplySurface = TTF_RenderText_Solid(MyText.Font, "*", MyText.NumberTextColor);
        if (MyText.MultiplySurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.MultiplySurface, nullptr, GetSurface(), &MyText.MultiplyPosition);
        }
    }
    void DrawResultButton()
    {
        if (MyText.ResultSurface != nullptr)
        {
            SDL_FreeSurface(MyText.ResultSurface);
        }
        MyText.ResultSurface = TTF_RenderText_Solid(MyText.Font, "=", MyText.NumberTextColor);
        if (MyText.ResultSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.ResultSurface, nullptr, GetSurface(), &MyText.ResultPosition);
        }
    }
    void DrawLastTextDeleteButton()
    {
        if (MyText.LastTextDeleteSurface != nullptr)
        {
            SDL_FreeSurface(MyText.LastTextDeleteSurface);
        }
        MyText.LastTextDeleteSurface = TTF_RenderText_Solid(MyText.Font, "<-", MyText.NumberTextColor);
        if (MyText.LastTextDeleteSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.LastTextDeleteSurface, nullptr, GetSurface(), &MyText.LastTextDeletePosition);
        }
    }
    void TextClearButton()
    {
        if (MyText.TextClearSurface != nullptr)
        {
            SDL_FreeSurface(MyText.TextClearSurface);
        }
        MyText.TextClearSurface = TTF_RenderText_Solid(MyText.Font, "C", MyText.NumberTextColor);
        if (MyText.TextClearSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.TextClearSurface, nullptr, GetSurface(), &MyText.TextClearPosition);
        }
    }
    void DrawResultBoard()
    {
        ResultBoardRect.x = 30;
        ResultBoardRect.y = 30;
        ResultBoardRect.w = 340;
        ResultBoardRect.h = 120;
        Uint32 ResultBoardRectColor = SDL_MapRGB(GetSurface()->format, 240, 240, 240);
        SDL_FillRect(GetSurface(), &ResultBoardRect, ResultBoardRectColor);  // Surface에 결과창 그리기
    }
};