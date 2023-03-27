#pragma once
#ifndef __BUSINESS_PUZZLEGAME_HUARONGDAO_HPP__
#define __BUSINESS_PUZZLEGAME_HUARONGDAO_HPP__

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

class Huarongdao
{
public:
    Huarongdao() {};
    int pzz[9] = { 1,2,3,4,5,6,7,8,0 };

    bool start;
    /**
    * @brief 定义显示棋盘(//Linux终端上)
    */
    void showpuzzle();//Linux终端上

    void move(string direct);
    /*
    * @brief 华容道游戏运行函数(Linux终端上)
    */
    int hrdmain();
};

#endif