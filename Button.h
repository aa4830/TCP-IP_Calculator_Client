#pragma once

#include <SDL.h>
#include "Rectangle.h"

class Button : public Rectangle 
{
public:
    virtual void HandleLeftClick()
    {
        std::cout << "Button Click" << std::endl;
    }

    Button(int x, int y, int w, int h) : Rectangle{ x, y, w, h } {}

    void HandleEvent(const SDL_Event& E) 
    {
        if (E.type == SDL_MOUSEBUTTONDOWN)
        {
            HandleMouseButton(E.button);
        }
    };
    
    void HandleMouseButton(const SDL_MouseButtonEvent& E)
    {
            const Uint8 Button{ E.button };
            if (Button == SDL_BUTTON_LEFT)
            {
                HandleLeftClick();
            }
    }
};
