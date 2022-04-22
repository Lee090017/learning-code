/*
 * @Author: your name
 * @Date: 2022-04-18 22:07:28
 * @LastEditTime: 2022-04-18 22:26:18
 * @LastEditors: Please set LastEditors
 * @Description: 菱形继承
 * @FilePath: \learningCode\project_03\extendTest4.cpp
 */

#include<iostream>
#include<string>

using namespace std;

class Animal{
public:
    int m_age;
};

//加virtual变成虚继承，Animal变为虚基类
class Cheep:virtual public Animal{
public:
    // int m_age;
};

class Tuo:virtual public Animal{
public:
    // int m_age;
};

class YangTuo:public Cheep,public Tuo{
public:
    // int m_age;
};

int main(){
    YangTuo yt;
    //菱形继承，两个父类拥有相同的数据，需要加作用域区分
    yt.Cheep::m_age = 18;
    yt.Tuo::m_age = 28;

    //虚继承使得数据共享
    //虚基类指针指和虚基表的便宜可以指向同一个数据m_age
    cout << "Cheep m_age: " << yt.Cheep::m_age << endl;
    cout << "Tuo m_age: " << yt.Tuo::m_age << endl;//28
    cout << "YangTuo m_age: " << yt.m_age << endl;//28

    //浪费资源
    



    return 0;
}
