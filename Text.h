#pragma once
#include <SDL.h>
#include <string>
#include <SDL_ttf.h>

class Text
{
public:
    TTF_Font* Font{ nullptr };
    SDL_Surface* TextSurface{ nullptr };
    SDL_Rect DestinationRectangle{ 280, 10, 100, 100 };

    Text()
    {
        CreateSurface("X");
    };

    Text(std::string Content, int Size = 25) : Font{ TTF_OpenFont("C:\\Work\\TCP-IP_Client\\Fonts\\AdultFont.ttf", Size) }
    {
        if (Font == NULL) 
        {
            printf("Could not open font! (%s)\n", TTF_GetError());
            return;
        }
        CreateSurface(Content);
    }

    void SetFontSize(int NewFontSize)
    {
        TTF_SetFontSize(Font, NewFontSize);
    }

    void Render(SDL_Surface* DestinationSurface)
    {
        SDL_BlitSurface(TextSurface, nullptr,DestinationSurface, &DestinationRectangle);
    }

    void CreateSurface(std::string Content) 
    {
        SDL_Surface* NewSurface = TTF_RenderUTF8_Blended(Font, Content.c_str(), { 255, 255, 255 } );
        if (NewSurface !=0)
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