/*
 * @Author: your name
 * @Date: 2022-04-06 21:35:27
 * @LastEditTime: 2022-04-06 21:37:48
 * @LastEditors: Please set LastEditors
 * @Description: swap源文件
 * @FilePath: \learningCode\project_01\swap.cpp
 */
#include "swap.h"

void swap(int a,int b){//形参列表
    int temp = a;
    a = b;
    b = temp;
    cout << a << endl;
    cout << b << endl;
}