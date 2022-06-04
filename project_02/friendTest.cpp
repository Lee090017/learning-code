/*
 * @Author: your name
 * @Date: 2022-04-13 15:47:06
 * @LastEditTime: 2022-04-13 16:52:48
 * @LastEditors: Please set LastEditors
 * @Description: 友员
 * @FilePath: \learningCode\project_02\friendTest.cpp
 */

/**
 * @file friendTest.cpp
 * @author your name (you@domain.com)
 * @brief 友元的目的就是让一个函数或者类 访问另一个类中私有成员
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<string>
using namespace std;

class Buildings;//需要提前声明

class Girlfriend{
public:
    Girlfriend();

    void visit1();//让visit函数可以访问Building中私有成员
    void visit2();//让visit函数不可以访问Building中私有成员

private:
    Buildings * g_building;

};

class Buildings{

    //设置友员，该函数是Buildings的好朋友，可以访问Buildings中的私有成员
    friend void goodfriend(Buildings *building);
    friend class GoodGay;
    friend void Girlfriend::visit1();
    

public:
    string m_Sitingroom;

    Buildings(){
        m_Sitingroom = "客厅";
        m_Bedroom = "卧室";
    }

    Buildings(string s,string b);

private:
    string m_Bedroom;

};

//类外写成员函数
Buildings::Buildings(string s,string b){
    m_Sitingroom = s;
    m_Bedroom = b;
}


class GoodGay{
public:
    Buildings * building;

    GoodGay();

    void visit();

};

GoodGay::GoodGay(){
    building = new Buildings;
}

//2.类做友员
void GoodGay::visit(){
    cout << "好朋友正在访问" << building->m_Sitingroom <<endl;
    cout << "好朋友正在访问" << building->m_Bedroom <<endl;//需要设置该类为友员类
}

//1.全局函数做友员
void goodfriend(Buildings *building){
    cout << "好朋友正在访问" << building->m_Sitingroom <<endl;
    cout << "好朋友正在访问" << building->m_Bedroom <<endl;//需要设置该全局函数为友员
}


Girlfriend::Girlfriend(){
    g_building = new Buildings("厨房","卫生间");
}

//3.成员函数做友员
void Girlfriend::visit1(){
    cout << "好朋友正在访问" << g_building->m_Sitingroom <<endl;
    cout << "好朋友正在访问" << g_building->m_Bedroom <<endl;
}

void Girlfriend::visit2(){
    cout << "好朋友正在访问" << g_building->m_Sitingroom <<endl;
    // cout << "好朋友正在访问" << building->m_Bedroom <<endl;
}

void test01(){
    Buildings b;
    goodfriend(&b);
}

void test02(){
    GoodGay g;
    g.visit();
}

void test03(){
    Girlfriend g;
    g.visit1();
}

int main() {
    test01();
    cout << "====================" << endl;
    test02();
    cout << "====================" << endl;
    test03();

    return 0;
}
