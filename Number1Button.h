#pragma once
#include "Button.h"
#include "Text.h"
#include "Window.h"

extern Window MyWindow;
extern Text MyText;

class Number1Button : public Button
{
public:
    Number1Button(int x, int y, int w, int h) : Button(x, y, w, h) 
    {

    }

    void HandleLeftClick() override
    {
        std::cout << "S" << std::endl;

    }
};