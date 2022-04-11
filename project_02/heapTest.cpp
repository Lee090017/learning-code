/*
 * @Author: your name
 * @Date: 2022-04-11 21:30:23
 * @LastEditTime: 2022-04-11 21:40:03
 * @LastEditors: Please set LastEditors
 * @Description: 堆区
 * @FilePath: \learningCode\project_02\heapTest..cpp
 */

#include<iostream>
using namespace std;

int * func_2(){
    //new可以在堆区开辟一块内存，并返回对应内存的地址
    //本质上局部变量p依然保存在栈区，但其保存的是对应栈区的地址
    int * p = new int(10);
    return p;
}

int main(){

    //在堆区开辟数据
    int * p = func_2();
    cout << *p << endl;

    return 0;
}
