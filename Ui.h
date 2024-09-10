#pragma once
#include "Button.h"

class UI 
{
public:
    Button MyButton{ 50, 50, 50, 50 };

    void Render(SDL_Surface* Surface) 
    {
        MyButton.Render(Surface); // Surface표면에 Button을 그리기.
    }

    void HandleEvent(const SDL_Event& E)
    {
        MyButton.HandleEvent(E);
    }

};