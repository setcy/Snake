#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
#include "map.h"
#include "snake.h"
#include "food.h"

void Controller::Start()
{
    SetWindowSize(41, 32);
    SetColor(2);
    StartInterface *start = new StartInterface();
    start->Action();
    delete start;

    SetCursorPosition(13, 26);
    std::cout << "Press any key to start... " ;
    SetCursorPosition(13, 27);
    system("pause");
}

//选择模式
void Controller::Select()
{
    SetColor(3);
    SetCursorPosition(13, 26);
    std::cout << "                          " ;
    SetCursorPosition(13, 27);\
    std::cout << "                          " ;
    SetCursorPosition(6, 21);
    std::cout << "请选择游戏模式" ;
    SetCursorPosition(6, 22);
    std::cout << "（上下键选择，回车键确认）" ;
    SetCursorPosition(27, 22);
    SetBackColor();
    std::cout << "普通模式" ;
    SetCursorPosition(27, 24);
    SetColor(3);
    std::cout << "闯关模式" ;
    SetCursorPosition(27, 26);
    std::cout << "生存模式" ;
    SetCursorPosition(27, 28);
    std::cout << "无界模式" ;
    SetCursorPosition(0, 31);
    score = 0;

    
    int ch;
    key = 11;
    bool flag = false;
    while ((ch = getch()))
    {
        switch (ch)
        {
        case 72:
            if (key > 11)
            {
                switch (key)
                {
                case 21:
                    SetCursorPosition(27, 22);
                    SetBackColor();
                    std::cout << "普通模式" ;

                    SetCursorPosition(27, 24);
                    SetColor(3);
                    std::cout << "闯关模式" ;

                    key=key-10;
                    break;
                case 31:
                    SetCursorPosition(27, 24);
                    SetBackColor();
                    std::cout << "闯关模式" ;

                    SetCursorPosition(27, 26);
                    SetColor(3);
                    std::cout << "生存模式" ;

                    key=key-10;
                    break;
                case 41:
                    SetCursorPosition(27, 26);
                    SetBackColor();
                    std::cout << "生存模式" ;

                    SetCursorPosition(27, 28);
                    SetColor(3);
                    std::cout << "无界模式" ;

                    key=key-10;
                    break;
                }
            }
            break;

        case 80:
            if (key < 41)
            {
                switch (key)
                {
                case 11:
                    SetCursorPosition(27, 24);
                    SetBackColor();
                    std::cout << "闯关模式" ;
                    SetCursorPosition(27, 22);
                    SetColor(3);
                    std::cout << "普通模式" ;

                    key=key+10;
                    break;
                case 21:
                    SetCursorPosition(27, 26);
                    SetBackColor();
                    std::cout << "生存模式" ;
                    SetCursorPosition(27, 24);
                    SetColor(3);
                    std::cout << "闯关模式" ;

                    key=key+10;
                    break;
                case 31:
                    SetCursorPosition(27, 28);
                    SetBackColor();
                    std::cout << "无界模式" ;
                    SetCursorPosition(27, 26);
                    SetColor(3);
                    std::cout << "生存模式" ;

                    key=key+10;
                    break;
                }
            }
            break;

        case 13:
            flag = true;
            break;
        default:
            break;
        }
        if (flag){
            if(key==11) Selectdifficulty();
            if(key==31) Selectdifficulty();
            if(key==41) Selectdifficulty();
            break;
        }

        SetCursorPosition(0, 31);
    }
    switch (key)
    {
    case 11:
        speed = 135;
        break;
    case 12:
        speed = 100;
        break;
    case 13:
        speed = 60;
        break;
    case 14:
        speed = 30;
        break;
    case 21:
        speed = 135;
        break;
    case 31:
        speed = 135;
        break;
    case 32:
        speed = 100;
        break;
    case 33:
        speed = 60;
        break;
    case 34:
        speed = 30;
        break;
    case 41:
        beginlen = 20;
        speed = 125;
        break;
    case 42:
        beginlen = 20;
        speed = 90;
        break;
    case 43:
        beginlen = 20;
        speed = 50;
        break;
    case 44:
        beginlen = 20;
        speed = 20;
        break;
    default:
        break;
    }
}
//选择难度
void Controller::Selectdifficulty()
{
    SetColor(3);
    SetCursorPosition(13, 26);
    std::cout << "                          " ;
    SetCursorPosition(13, 27);
    std::cout << "                          " ;
    SetCursorPosition(6, 21);
    std::cout << "请选择游戏难度" ;
    SetCursorPosition(6, 22);
    std::cout << "（上下键选择，回车键确认）" ;
    SetCursorPosition(27, 22);
    SetBackColor();
    std::cout << "简单模式" ;
    SetCursorPosition(27, 24);
    SetColor(3);
    std::cout << "普通模式" ;
    SetCursorPosition(27, 26);
    std::cout << "困难模式" ;
    SetCursorPosition(27, 28);
    std::cout << "炼狱模式" ;
    SetCursorPosition(0, 31);
    score = 0;

    
    int ch;
    bool flag = false;
    while ((ch = getch()))
    {
        switch (ch)
        {
        case 72:
            if (key%10 > 1)
            {
                switch (key%10)
                {
                case 2:
                    SetCursorPosition(27, 22);
                    SetBackColor();
                    std::cout << "简单模式" ;

                    SetCursorPosition(27, 24);
                    SetColor(3);
                    std::cout << "普通模式" ;

                    --key;
                    break;
                case 3:
                    SetCursorPosition(27, 24);
                    SetBackColor();
                    std::cout << "普通模式" ;

                    SetCursorPosition(27, 26);
                    SetColor(3);
                    std::cout << "困难模式" ;

                    --key;
                    break;
                case 4:
                    SetCursorPosition(27, 26);
                    SetBackColor();
                    std::cout << "困难模式" ;

                    SetCursorPosition(27, 28);
                    SetColor(3);
                    std::cout << "炼狱模式" ;

                    --key;
                    break;
                }
            }
            break;

        case 80:
            if (key%10 < 4)
            {
                switch (key%10)
                {
                case 1:
                    SetCursorPosition(27, 24);
                    SetBackColor();
                    std::cout << "普通模式" ;
                    SetCursorPosition(27, 22);
                    SetColor(3);
                    std::cout << "简单模式" ;

                    ++key;
                    break;
                case 2:
                    SetCursorPosition(27, 26);
                    SetBackColor();
                    std::cout << "困难模式" ;
                    SetCursorPosition(27, 24);
                    SetColor(3);
                    std::cout << "普通模式" ;

                    ++key;
                    break;
                case 3:
                    SetCursorPosition(27, 28);
                    SetBackColor();
                    std::cout << "炼狱模式" ;
                    SetCursorPosition(27, 26);
                    SetColor(3);
                    std::cout << "困难模式" ;

                    ++key;
                    break;
                }
            }
            break;

        case 13:
            flag = true;
            break;
        default:
            break;
        }
        if (flag) break;

        SetCursorPosition(0, 31);
    }

}

//游戏界面初始化
void Controller::DrawGame()
{
    system("cls");

    SetColor(3);
    
    Map *init_map = new Map();
    init_map->PrintInitmap();
    delete init_map;
    


    SetColor(3);
    SetCursorPosition(33, 1);
    std::cout << "Greedy Snake" ;
    SetCursorPosition(34, 2);
    std::cout << "贪吃蛇" ;
    SetCursorPosition(31, 4);
    std::cout << "模式：" ;
    SetCursorPosition(34, 5);
    switch (key)
    {
    case 11:
        std::cout << "简单模式" ;
        break;
    case 12:
        std::cout << "普通模式" ;
        break;
    case 13:
        std::cout << "困难模式" ;
        break;
    case 14:
        std::cout << "炼狱模式" ;
        break;
    case 21:
        std::cout << "闯关模式" ;
        break;
    case 31:
        std::cout << "生存-简单模式" ;
        break;
    case 32:
        std::cout << "生存-普通模式" ;
        break;
    case 33:
        std::cout << "生存-困难模式" ;
        break;
    case 34:
        std::cout << "生存-炼狱模式" ;
        break;
    case 41:
        std::cout << "无界-简单模式" ;
        break;
    case 42:
        std::cout << "无界-普通模式" ;
        break;
    case 43:
        std::cout << "无界-困难模式" ;
        break;
    case 44:
        std::cout << "无界-炼狱模式" ;
        break;
    default:
        break;
    }
    SetCursorPosition(31, 7);
    if(key/10==2){
        std::cout << "等级：" ;
    }
    else{
        std::cout << "得分：" ;
    }
    SetCursorPosition(37, 8);
    std::cout << "0" ;
    SetCursorPosition(33, 13);
    std::cout << "方向键移动" ;
    SetCursorPosition(33, 15);
    std::cout << "ESC键暂停" ;
}

//开始游戏
int Controller::PlayGame()
{
    Snake *csnake = new Snake();
    Food *cfood = new Food();
    SetColor(6);
    csnake->InitSnake();
    srand((unsigned)time(NULL));
    beginflag=1;
    liveflag=1;
    if(key/10!=4) cfood->DrawFood(*csnake);
    while (csnake->OverEdge() && csnake->HitItself())
    {
        if(key/10==4){
            if(beginlen>0){
                csnake->Move(key);
                beginlen--;
            }
            else{
                if(beginlen==0&&beginflag==1){
                    cfood->DrawFood(*csnake);
                    beginflag=0;
                }
            }
        }


        if (!csnake->ChangeDirection())
        {
            int tmp = Menu();
            switch (tmp)
            {
            case 1:
                break;

            case 2:
                delete csnake;
                delete cfood;
                return 1;

            case 3:
                delete csnake;
                delete cfood;
                return 2;

            default:
                break;
            }
        }

        if (csnake->GetFood(*cfood))
        {
            csnake->Move(key);
            UpdateScore(1);
            RewriteScore();
            cfood->DrawFood(*csnake);
            if(key/10==2){
                speed*=0.95;
            }
        }
        else
        {
            if(key/10==3){
                if(liveflag!=0){
                    csnake->NormalMove(key);
                }
                else{
                    csnake->Move(key);
                }
                liveflag++;
                liveflag%=5;
            }
            else{
                csnake->NormalMove(key);
            }
        }

        if (csnake->GetBigFood(*cfood))
        {
            csnake->Move(key);
            UpdateScore(cfood->GetProgressBar()/5);
            RewriteScore();
        }

        if (cfood->GetBigFlag())
        {
            cfood->FlashBigFood();
        }
        SetCursorPosition(0, 31);
        Sleep(speed);
    }

    delete csnake;
    delete cfood;
    int tmp = GameOver();
    switch (tmp)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        return 2;
    }
}


void Controller::UpdateScore(const int& tmp)
{
    if(key/10==2){
        score++;
        return;
    }
    switch (key%10)
    {
    case 1:
        score += 1 * 10 * tmp;
        break;
    case 2:
        score += 2 * 10 * tmp;
        break;
    case 3:
        score += 3 * 10 * tmp;
        break;
    case 4:
        score += 4 * 10 * tmp;
        break;
    default:
        break;
    }
}

void Controller::RewriteScore()
{
    SetCursorPosition(37, 8);
    SetColor(11);
    int bit = 0;
    int tmp = score;
    while (tmp != 0)
    {
        ++bit;
        tmp /= 10;
    }
    for (int i = 0; i < (6 - bit); ++i)
    {
        std::cout << " " ;
    }
    std::cout << score ;
}

//显示菜单
int Controller::Menu()
{
    SetColor(11);
    SetCursorPosition(32, 19);
    std::cout << "菜单：" ;
    Sleep(100);
    SetCursorPosition(34, 21);
    SetBackColor();
    std::cout << "继续游戏" ;
    Sleep(100);
    SetCursorPosition(34, 23);
    SetColor(11);
    std::cout << "重新开始" ;
    Sleep(100);
    SetCursorPosition(34, 25);
    std::cout << "退出游戏" ;
    SetCursorPosition(0, 31);

    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = getch()))
    {
        switch (ch)
        {
        case 72://UP
            if (tmp_key > 1)
            {
                switch (tmp_key)
                {
                case 2:
                    SetCursorPosition(34, 21);
                    SetBackColor();
                    std::cout << "继续游戏" ;
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "重新开始" ;

                    --tmp_key;
                    break;
                case 3:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "重新开始" ;
                    SetCursorPosition(34, 25);
                    SetColor(11);
                    std::cout << "退出游戏" ;

                    --tmp_key;
                    break;
                }
            }
            break;

        case 80://DOWN
            if (tmp_key < 3)
            {
                switch (tmp_key)
                {
                case 1:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "重新开始" ;
                    SetCursorPosition(34, 21);
                    SetColor(11);
                    std::cout << "继续游戏" ;

                    ++tmp_key;
                    break;
                case 2:
                    SetCursorPosition(34, 25);
                    SetBackColor();
                    std::cout << "退出游戏" ;
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "重新开始" ;

                    ++tmp_key;
                    break;
                }
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        if (flag)
        {
            break;
        }
        SetCursorPosition(0, 31);
    }

    if (tmp_key == 1)
    {
        SetCursorPosition(32, 19);
        std::cout << "          " ;
        SetCursorPosition(34, 21);
        std::cout << "          ";
        SetCursorPosition(34, 23);
        std::cout << "          ";
        SetCursorPosition(34, 25);
        std::cout << "          ";
    }
    return tmp_key;
}

void Controller::Game()
{
    Start();
    while (true)
    {
        Select();
        DrawGame();
        int tmp = PlayGame();
        if (tmp == 1)
        {
            system("cls");
        }
        else if (tmp == 2)
        {
            break;
        }
        else
        {
            break;
        }
        StartInterface *restart = new StartInterface();
        restart->PrintText(1);
        delete restart;
    }
}

int Controller::GameOver()
{
    Sleep(500);
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "—————————————————————" ;
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << "|               Game Over !!!              |" ;
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << "|                                          |" ;
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << "|              很遗憾！你挂了              |" ;
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << "|                                          |" ;
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << "|              你的分数为：                |" ;
    SetCursorPosition(24, 13);
    std::cout << score ;
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << "|                                          |" ;
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << "|是否再来一局？                            |" ;
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << "|                                          |" ;
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << "|                                          |" ;
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << "|     嗯，好的        不了，还是学习有意思 |" ;
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << "|                                          |" ;
    Sleep(30);
    SetCursorPosition(9, 20);
    std::cout << "|                                          |" ;
    Sleep(30);
    SetCursorPosition(10, 21);
    std::cout << "—————————————————————" ;

    Sleep(100);
    SetCursorPosition(12, 18);
    SetBackColor();
    std::cout << "嗯，好的" ;
    SetCursorPosition(0, 31);

    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = getch()))
    {
        switch (ch)
        {
        case 75://LEFT
            if (tmp_key > 1)
            {
                SetCursorPosition(12, 18);
                SetBackColor();
                std::cout << "嗯，好的" ;
                SetCursorPosition(20, 18);
                SetColor(11);
                std::cout << "不了，还是学习有意思" ;
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                SetCursorPosition(20, 18);
                SetBackColor();
                std::cout << "不了，还是学习有意思" ;
                SetCursorPosition(12, 18);
                SetColor(11);
                std::cout << "嗯，好的" ;
                ++tmp_key;
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        SetCursorPosition(0, 31);
        if (flag) {
            break;
        }
    }


    SetColor(11);
    switch (tmp_key)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        return 1;
    }
}
