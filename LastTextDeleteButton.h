#pragma once
#include "Button.h"
#include "Text.h"
#include "Window.h"

extern Window MyWindow;
extern Text MyText;

class LastTextDeleteButton : public Button
{
public:
    LastTextDeleteButton(int x, int y, int w, int h) : Button(x, y, w, h)
    {

    }

    void HandleLeftClick() override
    {
        if (MyText.ResultTextSurface != nullptr)
        {
            SDL_Surface* screenSurface = MyWindow.GetSurface();
            SDL_FillRect(screenSurface, &MyText.ResultTextPosition, SDL_MapRGB(screenSurface->format, 240, 240, 240));
            SDL_FreeSurface(MyText.ResultTextSurface);
            MyText.ResultTextSurface = nullptr;
        }
        std::string CurrentText = MyText.CurrentText; 
        if (!CurrentText.empty())
        {
            CurrentText.pop_back();
        }
        MyText.CurrentText = CurrentText;

        MyText.ResultTextSurface = TTF_RenderText_Solid(MyText.Font, MyText.CurrentText.c_str(), MyText.ResultTextColor);
        if (MyText.ResultTextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.ResultTextSurface, nullptr, MyWindow.GetSurface(), &MyText.ResultTextPosition);
            MyWindow.Update();
        }
    }

};