#pragma once
#include "Button.h"

class UI 
{
public:
    void Render(SDL_Surface* Surface) 
    {
        MyButton.Render(Surface);
    }

    void HandleEvent(const SDL_Event& E)
    {
        MyButton.HandleEvent(E);
    }

    Button MyButton{ 50, 50, 50, 50 };
};