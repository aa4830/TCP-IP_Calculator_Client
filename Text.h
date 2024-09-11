#pragma once
#include <SDL.h>
#include <string>
#include <SDL_ttf.h>

class Text
{
public:
    TTF_Font* Font = nullptr;
    SDL_Color ResultTextColor = { 0, };
    SDL_Color NumberTextColor = { 0, };
    SDL_Surface* ResultTextSurface = nullptr;
    SDL_Surface* Number1TextSurface = nullptr;
    SDL_Surface* Number2TextSurface = nullptr;
    SDL_Surface* Number3TextSurface = nullptr;
    SDL_Surface* Number4TextSurface = nullptr;
    SDL_Surface* Number5TextSurface = nullptr;
    SDL_Surface* Number6TextSurface = nullptr;
    SDL_Surface* Number7TextSurface = nullptr;
    SDL_Surface* Number8TextSurface = nullptr;
    SDL_Surface* Number9TextSurface = nullptr;
    SDL_Surface* Number0TextSurface = nullptr;
    SDL_Surface* DivideSurface = nullptr;
    SDL_Surface* AddSurface = nullptr;
    SDL_Surface* MinusSurface = nullptr;
    SDL_Surface* MultiplySurface = nullptr;
    SDL_Surface* ResultSurface = nullptr;
    SDL_Surface* LastTextDeleteSurface = nullptr;
    SDL_Surface* TextClearSurface = nullptr;

    SDL_Rect ResultTextPosition = { 0, };
    SDL_Rect Number1TextPosition = { 0, };
    SDL_Rect Number2TextPosition = { 0, };
    SDL_Rect Number3TextPosition = { 0, };
    SDL_Rect Number4TextPosition = { 0, };
    SDL_Rect Number5TextPosition = { 0, };
    SDL_Rect Number6TextPosition = { 0, };
    SDL_Rect Number7TextPosition = { 0, };
    SDL_Rect Number8TextPosition = { 0, };
    SDL_Rect Number9TextPosition = { 0, };
    SDL_Rect Number0TextPosition = { 0, };
    SDL_Rect DividePosition = { 0, };
    SDL_Rect AddPosition = { 0, };
    SDL_Rect MinusPosition = { 0, };
    SDL_Rect MultiplyPosition = { 0, };
    SDL_Rect ResultPosition = { 0, };
    SDL_Rect LastTextDeletePosition = { 0, };
    SDL_Rect TextClearPosition = { 0, };
    std::string CurrentText;
    std::string NewText;

    Text()
    {
        TTF_Init();
        Font = TTF_OpenFont("C:\\Work\\TCP-IP_Client\\Fonts\\ArialTh.ttf", 50);
        if (Font == nullptr)
        {
            printf("Failed to load font: %s\n", TTF_GetError());
        }
        ResultTextColor = { 0, 0, 0 };
        NumberTextColor = { 255, 255, 255 }; 
        ResultTextPosition = { 30,30,80,80 };
        Number1TextPosition = { 50,435,60,60 };
        Number2TextPosition = { 140,435,60,60 }; 
        Number3TextPosition = { 230,435,60,60 };
        Number4TextPosition = { 50,345,60,60 };
        Number5TextPosition = { 140,345,60,60 };
        Number6TextPosition = { 230,345,60,60 };
        Number7TextPosition = { 50,255,60,60 };
        Number8TextPosition = { 140,255,60,60 }; 
        Number9TextPosition = { 230,255,60,60 };
        Number0TextPosition = { 140,525,60,60 };
        DividePosition = { 320,165,60,60 };
        AddPosition = { 320,435,60,60 };
        MinusPosition = { 320,345,60,60 };
        MultiplyPosition = { 320,255,60,60 };
        ResultPosition = { 320,525,60,60 };
        LastTextDeletePosition = { 230,165,60,60 };
        TextClearPosition = { 140,165,60,60 };

    };

    ~Text()
    {
        SDL_FreeSurface(ResultTextSurface);
        if (TTF_WasInit()) 
        {
            TTF_CloseFont(Font);
        }
    }

};