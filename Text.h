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
    SDL_Rect ResultTextPosition = { 0, };
    SDL_Rect Number1TextPosition = { 0, };
    std::string CurrentText;
    std::string NewText;

    Text()
    {
        TTF_Init();
        Font = TTF_OpenFont("C:\\Work\\TCP-IP_Client\\Fonts\\AdultFont.ttf", 100);
        if (Font == nullptr)
        {
            printf("Failed to load font: %s\n", TTF_GetError());
        }
        ResultTextColor = { 0, 0, 0 };
        NumberTextColor = { 255, 255, 255 };
        ResultTextPosition = { 30,30,80,80 };
        Number1TextPosition = { 55,450,80,80 };
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