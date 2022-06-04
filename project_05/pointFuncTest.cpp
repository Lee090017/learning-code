/*
 * @Author: Lee090017 455938969@qq.com
 * @Date: 2022-05-31 18:32:35
 * @LastEditors: Lee090017 455938969@qq.com
 * @LastEditTime: 2022-05-31 18:47:58
 * @FilePath: \learningCode\project_05\pointFuncTest.cpp
 * @Description: 函数指针和指针函数
 * 
 * 
 （1） 定义不同
指针函数本质是一个函数，其返回值为指针。

函数指针本质是一个指针，其指向一个函数。

（2）写法不同
指针函数：int* fun(int x,int y);

函数指针：int (*fun)(int x,int y);

（3）用法不同

一个是函数，一个是变量。
 */

#include<iostream>
#include<string.h>

using namespace std;

int * fun(int x,int y){
    int *p = (int *)malloc(sizeof(int));//内存分配malloc
    memset(p, 0, sizeof(int));//将p中当前位置后面的sizeof(int)个字节用0替换并返回p 。
    printf("函数内:p = 0x%x \n", p);
    *p = x + y;
    printf("函数内:*p = %d \n", *p);
    return p;
}

int addNum(int x,int y) {
    return x+y;
}

int subNum(int x,int y) {
    return x-y;
}

int (*func)(int x,int y);//申明函数指针

/**
 * @brief 
 * 
 * 指针函数：返回指针
 * 
 */
void test01(){
    int * res = fun(1,2);
    cout << "res = " << res << endl;
    cout << "*res = " << *res << endl;
}

/**
 * @brief 
 * 
 * 函数指针：指向函数的指针
 * 
 */
void test02(){
    //写法一：直接函数命名
    func = addNum;
    cout << "(*func)(1,2) = " << (*func)(1,2) << endl;
    //写法二：函数的地址命名
    func = &subNum;
    cout << "(*func)(1,2) = " << func(1,2) << endl; 
}

int main() {
    test02();

    return 0;
}