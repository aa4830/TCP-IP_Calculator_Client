#pragma once
#include <SDL.h>

class Rectangle 
{
public:
    SDL_Rect Rect{ 0, 0, 0, 0 };

	Rectangle(int x, int y, int w, int h) : Rect{ x, y, w, h } {}

    void Render(SDL_Surface* Surface)
    {
        SDL_FillRect(Surface, &Rect, SDL_MapRGB(Surface->format, 0, 0, 0));
    }

    bool IsWithinBounds(int x, int y) const 
    {
        // Too far left
        if (x < Rect.x) return false;
        // Too far right
        if (x > Rect.x + Rect.w) return false;
        // Too high
        if (y < Rect.y) return false;
        // Too low
        if (y > Rect.y + Rect.h) return false;
        // Within bounds
        return true;
    }
    
};