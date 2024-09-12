#pragma once
#include "Button.h"
#include "Text.h"
#include "Window.h"

extern Window MyWindow;
extern Text MyText;

class TextClearButton : public Button
{
public:
    TextClearButton(int x, int y, int w, int h) : Button(x, y, w, h)
    {

    }

    void HandleLeftClick() override
    {
        std::cout << "s" << std::endl;
        if (MyText.ResultTextSurface != nullptr)
        {
            SDL_Surface* ScreenSurface = MyWindow.GetSurface();
            SDL_FillRect(ScreenSurface, &MyText.ResultTextPosition, SDL_MapRGB(ScreenSurface->format, 240, 240, 240)); //// 텍스트가 그려진 영역을 배경색으로 채워서 지운다
            SDL_FreeSurface(MyText.ResultTextSurface);  // 기존 텍스트 서페이스를 해제
            MyText.ResultTextSurface = nullptr;
        }

        MyText.CurrentText.clear();
        MyText.ResultTextSurface = TTF_RenderText_Solid(MyText.Font, MyText.CurrentText.c_str(), MyText.ResultTextColor);  // 수정된 텍스트로 새로운 서페이스를 생성
        SDL_BlitSurface(MyText.ResultTextSurface, nullptr, MyWindow.GetSurface(), &MyText.ResultTextPosition); // 새 텍스트를 화면에 그린다
    }

};