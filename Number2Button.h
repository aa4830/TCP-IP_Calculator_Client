#pragma once
#include "Button.h"
#include "Text.h"
#include "Window.h"

extern Window MyWindow;
extern Text MyText;

class Number2Button : public Button
{
public:
    Number2Button(int x, int y, int w, int h) : Button(x, y, w, h)
    {

    }

    void HandleLeftClick() override
    {
        std::string NewText = "2";
        if (MyText.ResultTextSurface != nullptr)
        {
            SDL_FreeSurface(MyText.ResultTextSurface);
        }
        MyText.ResultTextSurface = TTF_RenderText_Solid(MyText.Font, MyText.CurrentText.append(NewText).c_str(), MyText.ResultTextColor);
        if (MyText.ResultTextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.ResultTextSurface, nullptr, MyWindow.GetSurface(), &MyText.ResultTextPosition);
        }
    }

};