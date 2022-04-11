/*
 * @Author: your name
 * @Date: 2022-04-11 20:54:06
 * @LastEditTime: 2022-04-11 21:20:16
 * @LastEditors: Please set LastEditors
 * @Description: 全局区解析
 * @FilePath: \learningCode\project_02\globalTest.cpp
 */

/**
 * @file globalTest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * 总结：
 * C++中在程序运行前分为全局区和代码区
 * 代码区特点是共享和只读
 * 全局区中存放全局变量、静态变量、常量
 * 常量区中存放 const修饰的全局常量 和 字符串常量
 * 
 */
#include<iostream>
#include<string>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 20;

//全局常量
const int c_g_a = 10;

int main(){

    //全局区

    //全局变量、静态变量、常量

    //创建普通局部变量
    int a = 1;
    int b = 2;
    cout << "a = " << &a << endl;
    cout << "b = " << &b << endl;

    cout << "g_a = " << &g_a << endl;
    cout << "g_b = " << &g_b << endl;

    //静态变量
    static int s_a = 1;
    static int s_b = 2;

    cout << "s_a = " << &s_a << endl;
    cout << "s_b = " << &s_b << endl;//静态变量和全局变量均在全局区

    //常量
    //字符串常量
    cout << "hello = " << &"hello" << endl;

    //const变量
    //const修饰的全局变量
    cout << "c_g_a = " << &c_g_a << endl;
    //const修饰的局部变量
    const int c_a = 10;
    cout << "c_a = " << &c_a << endl;

    return 0;
}
