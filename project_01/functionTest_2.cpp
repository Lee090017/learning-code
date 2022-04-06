/*
 * @Author: your name
 * @Date: 2022-04-06 21:26:48
 * @LastEditTime: 2022-04-06 21:53:04
 * @LastEditors: Please set LastEditors
 * @Description: 函数的分文件编写
 * @FilePath: \learningCode\project_01\functionTest_2.cpp
 */

/*
    1.创建.h后缀名的头文件
    2.创建.cpp后缀名的源文件
    3.在头文件中写函数的声明
    4.在源文件中先函数的定义

*/

#include<iostream>
using namespace std;
// #include "swap.h"
#include "swap.cpp"

int main(){

    int a = 1;
    int b = 2;
    swap(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
