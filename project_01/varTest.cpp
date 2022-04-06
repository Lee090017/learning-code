/*
 * @Author: your name
 * @Date: 2022-04-05 16:18:08
 * @LastEditTime: 2022-04-05 16:29:47
 * @LastEditors: Please set LastEditors
 * @Description: 变量和常量
 * @FilePath: \learningCode\project_01\varTest.cpp
 */
#include <iostream>
using namespace std;

// 常量的定义
// #define 宏常量
// const 修饰的变量
#define Day 7 //常量不可修改

int main() {

    const int Month = 12;

    cout << "One week has " << Day << " days" << endl;
    cout << "One year has " << Month << " months" << endl;

    system("pause");
    return 0;
}
