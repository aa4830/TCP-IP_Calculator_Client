#pragma once

#include <SDL.h>
#include "Rectangle.h"

class Button : public Rectangle 
{
public:
    Button(int x, int y, int w, int h) : Rectangle{ x, y, w, h } {} //Rectangle의 생성자가 Button 생성자로부터 전달된 변수를 그대로 받는다.

    virtual void HandleLeftClick()
    {
       
    }

    void HandleEvent(const SDL_Event& E) 
    {
        if (E.type == SDL_MOUSEBUTTONDOWN)
        {
            HandleMouseButton(E.button);
        };
    }
    void HandleMouseButton(const SDL_MouseButtonEvent& E)
    {
        if (IsWithinBounds(E.x, E.y)) 
        {
            const Uint8 Button{ E.button };
            if (Button == SDL_BUTTON_LEFT)
            {
                HandleLeftClick();
            }
        }
    }
    
};