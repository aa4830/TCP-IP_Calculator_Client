#pragma once
#include "Button.h"
#include "Text.h"
#include "Socket.h"
#include "Window.h"

extern Window MyWindow;
extern Text MyText;

class ResultButton : public Button
{
public:

    Socket MySocket;

    ResultButton(int x, int y, int w, int h) : Button(x, y, w, h)
    {
    }
    ~ResultButton()
    {
    }

    void HandleLeftClick() override
    {
        MySocket.Send();
    }

};