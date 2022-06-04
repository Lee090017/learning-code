/*
 * @Author: your name
 * @Date: 2022-04-11 21:21:20
 * @LastEditTime: 2022-04-11 21:27:32
 * @LastEditors: Please set LastEditors
 * @Description: 栈区
 * @FilePath: \learningCode\project_02\stackTest.cpp
 */

#include<iostream>
#include<string>
using namespace std;

//栈区注意事项 -- 不要返回局部变量的地址
//栈区的数据由编译器管理开辟和释放
//由编译器自动分配释放, 存放函数的参数值,局部变量等

int * func(int x){//形参也在栈区
    int a = 1;
    return &a;//返回局部变量的地址
}

int main(){

    int * a = func(1);

    cout << *a << endl;

    return 0;
}