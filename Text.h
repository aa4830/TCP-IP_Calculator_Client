#pragma once
#include <SDL.h>
#include <string>
#include <SDL_ttf.h>

class Text
{
public:
    TTF_Font* Font = nullptr;
    SDL_Color TextColor = { 0, };
    SDL_Surface* TextSurface = nullptr;
    SDL_Rect TextPosition = { 0, };

    Text()
    {
        TTF_Init();
        Font = TTF_OpenFont("C:\\Work\\TCP-IP_Client\\Fonts\\AdultFont.ttf", 25);
        if (Font == nullptr)
        {
            printf("Failed to load font: %s\n", TTF_GetError());
        }
        TextColor = { 255, 255, 255 };
        TextPosition = { 280, 10, 100, 100 };
    };

    void SetFontSize(int NewFontSize)
    {
        TTF_SetFontSize(Font, NewFontSize);
    }

    void Render(SDL_Surface* DestinationSurface)
    {
        SDL_BlitSurface(TextSurface, nullptr,DestinationSurface, &TextPosition);
    }

    void CreateSurface(std::string Content) 
    {
        if (Font == nullptr)
        {
            printf("Font is not loaded: %s\n", TTF_GetError());
            return;
        }
        SDL_Surface* NewSurface = TTF_RenderText_Solid(Font, Content.c_str(), TextColor);
        if (NewSurface !=nullptr)
        {
            SDL_FreeSurface(TextSurface);
            TextSurface = NewSurface;
        }
    }

    ~Text()
    {
        SDL_FreeSurface(TextSurface);
        if (TTF_WasInit()) 
        {
            TTF_CloseFont(Font);
        }
    }

};