#pragma once
#include "Button.h"
#include "Number1Button.h"

class UI 
{
public:
    Number1Button MyNumber1Button{ 30,480,80,80 };

    void Render(SDL_Surface* Surface) 
    {
        MyNumber1Button.Render(Surface);
    }

    void HandleEvent(const SDL_Event& E)
    {
        MyNumber1Button.HandleEvent(E);
    }

};