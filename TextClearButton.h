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
            SDL_FillRect(ScreenSurface, &MyText.ResultTextPosition, SDL_MapRGB(ScreenSurface->format, 240, 240, 240)); //// �ؽ�Ʈ�� �׷��� ������ �������� ä���� �����
            SDL_FreeSurface(MyText.ResultTextSurface);  // ���� �ؽ�Ʈ �����̽��� ����
            MyText.ResultTextSurface = nullptr;
        }

        MyText.CurrentText.clear();
        MyText.ResultTextSurface = TTF_RenderText_Solid(MyText.Font, MyText.CurrentText.c_str(), MyText.ResultTextColor);  // ������ �ؽ�Ʈ�� ���ο� �����̽��� ����
        SDL_BlitSurface(MyText.ResultTextSurface, nullptr, MyWindow.GetSurface(), &MyText.ResultTextPosition); // �� �ؽ�Ʈ�� ȭ�鿡 �׸���
    }

};