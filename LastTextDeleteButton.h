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
            SDL_Surface* ScreenSurface = MyWindow.GetSurface();
            SDL_FillRect(ScreenSurface, &MyText.ResultTextPosition, SDL_MapRGB(ScreenSurface->format, 240, 240, 240)); //// �ؽ�Ʈ�� �׷��� ������ �������� ä���� �����
            SDL_FreeSurface(MyText.ResultTextSurface);  // ���� �ؽ�Ʈ �����̽��� ����
            MyText.ResultTextSurface = nullptr;
        }
        std::string CurrentText = MyText.CurrentText; 
        if (!CurrentText.empty())
        {
            CurrentText.pop_back();
        }
        MyText.CurrentText = CurrentText;

        MyText.ResultTextSurface = TTF_RenderText_Solid(MyText.Font, MyText.CurrentText.c_str(), MyText.ResultTextColor);  // ������ �ؽ�Ʈ�� ���ο� �����̽��� ����
        if (MyText.ResultTextSurface == nullptr)
        {
            printf("Font Missing %s\n", TTF_GetError());
        }
        else
        {
            SDL_BlitSurface(MyText.ResultTextSurface, nullptr, MyWindow.GetSurface(), &MyText.ResultTextPosition); // �� �ؽ�Ʈ�� ȭ�鿡 �׸���
        }
    }

};