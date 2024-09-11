#pragma once
#include "Button.h"
#include "Number1Button.h"
#include "Number2Button.h"
#include "Number3Button.h"
#include "Number4Button.h"
#include "Number5Button.h"
#include "Number6Button.h"
#include "Number7Button.h"
#include "Number8Button.h"
#include "Number9Button.h"
#include "Number0Button.h"
#include "DivideButton.h"
#include "MinusButton.h"
#include "MultiplyButton.h"
#include "LastTextDeleteButton.h"
#include "AddButton.h"
#include "TextClearButton.h"
#include "ResultButton.h"


class UI 
{
public:
    Number1Button MyNumber1Button{ 30,430,60,60 };
    Number2Button MyNumber2Button{ 120,430,60,60 };
    Number3Button MyNumber3Button{ 210,430,60,60 };
    Number4Button MyNumber4Button{ 30,340,60,60 };
    Number5Button MyNumber5Button{ 120,340,60,60 };
    Number6Button MyNumber6Button{ 210,340,60,60 };
    Number7Button MyNumber7Button{ 30,250,60,60 };
    Number8Button MyNumber8Button{ 120,250,60,60 };
    Number9Button MyNumber9Button{ 210,250,60,60 };
    Number0Button MyNumber0Button{ 120,520,60,60 };
    DivideButton MyDivideButton{ 300,160,60,60 };
    MinusButton MyMinusButton{ 300,340,60,60 };
    MultiplyButton MyMultiplyButton{ 300,250,60,60 };
    LastTextDeleteButton MyLastTextDeleteButton{ 210,160,60,60 };
    AddButton MyAddButton{ 300,430,60,60 };
    TextClearButton MyTextClearButton{ 120,160,60,60 };
    ResultButton MyResultButton{ 300,520,60,60 };

    void Render(SDL_Surface* Surface) 
    {
        MyNumber1Button.Render(Surface);
        MyNumber2Button.Render(Surface);
        MyNumber3Button.Render(Surface);
        MyNumber4Button.Render(Surface);
        MyNumber5Button.Render(Surface);
        MyNumber6Button.Render(Surface);
        MyNumber7Button.Render(Surface);
        MyNumber8Button.Render(Surface);
        MyNumber9Button.Render(Surface);
        MyNumber0Button.Render(Surface);
        MyDivideButton.Render(Surface);
        MyMinusButton.Render(Surface);
        MyMultiplyButton.Render(Surface);
        MyLastTextDeleteButton.Render(Surface);
        MyAddButton.Render(Surface);
        MyTextClearButton.Render(Surface);
        MyResultButton.Render(Surface);
    }

    void HandleEvent(const SDL_Event& E)
    {
        MyNumber1Button.HandleEvent(E);
        MyNumber2Button.HandleEvent(E);
        MyNumber3Button.HandleEvent(E);
        MyNumber4Button.HandleEvent(E);
        MyNumber5Button.HandleEvent(E);
        MyNumber6Button.HandleEvent(E);
        MyNumber7Button.HandleEvent(E);
        MyNumber8Button.HandleEvent(E);
        MyNumber9Button.HandleEvent(E);
        MyNumber0Button.HandleEvent(E);
        MyDivideButton.HandleEvent(E);
        MyMinusButton.HandleEvent(E);
        MyMultiplyButton.HandleEvent(E);
        MyLastTextDeleteButton.HandleEvent(E);
        MyAddButton.HandleEvent(E);
        MyTextClearButton.HandleEvent(E);
        MyResultButton.HandleEvent(E);

    }

};