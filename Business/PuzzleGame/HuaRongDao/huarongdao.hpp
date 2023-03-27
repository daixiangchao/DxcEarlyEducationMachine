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
    * @brief ������ʾ����(//Linux�ն���)
    */
    void showpuzzle();//Linux�ն���

    void move(string direct);
    /*
    * @brief ���ݵ���Ϸ���к���(Linux�ն���)
    */
    int hrdmain();
};

#endif