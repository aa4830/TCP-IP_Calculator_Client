#pragma once
#include "Button.h"
#include "Number1Button.h"

class UI 
{
public:
    Button MyButton{ 50, 50, 50, 50 };
    Number1Button MyNumber1Button{ 100,100,100,100 };

    void Render(SDL_Surface* Surface) 
    {
        MyButton.Render(Surface); // Surfaceǥ�鿡 Button�� �׸���.
        MyNumber1Button.Render(Surface);
    }

    void HandleEvent(const SDL_Event& E)
    {
        MyButton.HandleEvent(E);
        MyNumber1Button.HandleEvent(E);
    }

};