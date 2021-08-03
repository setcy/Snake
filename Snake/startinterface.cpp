#include "startinterface.h"
#include <windows.h>


void StartInterface::PrintFirst()
{
    for (auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);
    }
}

void StartInterface::PrintSecond()
{
    for (int i = 10; i != 40; ++i)
    {
        
        int j = ( ((i-2)%8) < 4 )?( 15 + (i-2)%8 ) : ( 21 - (i-2)%8 );
        startsnake.emplace_back( Point(i, j) );
        startsnake.back().Print();
        startsnake.front().Clear();
        startsnake.pop_front();
        Sleep(speed);
    }
}

void StartInterface::PrintThird()
{
    while ( !startsnake.empty() || textsnake.back().GetX() < 33 ) 
    {
        if ( !startsnake.empty() )
        {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        ClearText();
        PrintText(0);
        Sleep(speed);
    }
}

void StartInterface::PrintText(int restart)
{
    if(restart==0){
        for (auto& point : textsnake)
        {
            if (point.GetX() >= 0)
                point.Print();
        }
    }
    else{
        for (auto& point : textsnake)
        {
            point.ChangePosition(point.GetX() + 33, point.GetY());
            if (point.GetX() >= 0)
                point.Print();
        }
    }
}

void StartInterface::ClearText()
{
    for (auto& point : textsnake)
    {
        if (point.GetX() >= 0)
            point.Clear();
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }
}

void StartInterface::Action()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
}

