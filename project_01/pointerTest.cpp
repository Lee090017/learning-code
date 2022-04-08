/*
 * @Author: your name
 * @Date: 2022-04-08 15:32:02
 * @LastEditTime: 2022-04-08 18:13:03
 * @LastEditors: Please set LastEditors
 * @Description: 指针
 * @FilePath: \learningCode\project_01\pointerTest.cpp
 */

/**
 * @file pointerTest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * 利用指针保存数据的地址编号
 * 
 */

#include<iostream>
using namespace std;

void swap_2(int * a,int * b);
void bubble(int * arr,int len);

int main(){

    //定义指针 语法：数据类型 * 指针变量名
    int a = 10;
    int * p;
    p = &a;
    cout << "a's adress is " << &a << endl;
    cout << "p is " << p << endl;//变量p存放的是变量a的地址
    //使用指针
    //可以通过解引用的方式来找到指针指向的内存
    //* 表示解引用，找到指针指向内存中的数据，并且可以修改和访问这块内存
    *p = 1000;//
    cout << "*p is " << a << endl;//*p 为变量a所存的数字

    cout << "int * size of p is " << sizeof(p) << endl;//32位操作系统 为占用 4个字节，64位操作系统 占有 8个字节数据
    cout << "bool * size of p is " << sizeof(bool *) << endl;
    cout << "double * size of p is " << sizeof(double *) << endl;
    cout << "char * size of p is " << sizeof(char *) << endl;

    cout << "====================" << endl;

    //空指针：指针变量指向内存空间中编号为0的空间 用于初始化指针变量

    int * p1 = NULL;
    //*p1 = 100;//空指针不能进行访问
    
    //野指针：指针变量指向非法的空间
    /*
        int * p = (int *)0x110000;//该地位未申请内存(非法内存空间)
        cout << *p << endl;
    */

   //const修饰指针
   //1.const修饰指针 --常量指针
   //特点：指针的指向可以改，但指针指向的值不能修改
   int a1 = 10;
   int b1 = 20;
   const int * p2 = &a1;
   p2 = &b1;//更改指向
   // *p2 = 100;//不可修改内部的值
   cout << "*p2 = " << *p2 << endl;


   //2.const修饰常量 --指针常量
   //特点：指针的指向不可以改，但指针指向的值能修改
   int * const p3 = &a1;
   //p3 = &b1;//更改指向
   *p3 = 100;//不可修改内部的值
   cout << "*p3 = " << *p3 << endl;

   //3.const既修饰指针，又修饰常量
   //特点：指针的指向和指针指向的值都不可以改
   const int * const p4 = &a1;
   //p3 = &b1;//更改指向
   //*p4 = 100;//不可修改内部的值
   cout << "*p4 = " << *p4 << endl;

   cout << "====================" << endl;

   //指针和数组
   //利用指针访问数组中的元素
   int arr1[] = {1,2,3,4,5};

   int * p5 = arr1;

   cout << "arr1[0] = " << *p5 << endl;

   p5++;//由于 p5 为 int指针 让指针偏移4个字节

   cout << "arr1[1] = " << *p5 << endl;

   p5--;

   for(int i = 0; i < 5;i++){
       cout << *p5 << endl;
       p5++;
   }

   cout << "====================" << endl;

   //指针和函数
   int m = 1;
   int n = 2;
   swap_2(&m,&n);
   cout << "m = " << m << endl;
   cout << "n = " << n << endl;//对比值传递

   cout << "====================" << endl;

   int arr2[10] = {9,6,-3,7,1,18,0,1,-5,-10};
   bubble(arr2,10);
    for(int i = 0; i < 10;i++){
       cout << arr2[i] << " ";
    }
    cout << endl;

   return 0;
}

//地址传递
void swap_2(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//冒泡排序
void bubble(int * arr,int len){
    for(int i = len-1;i > 0; i-- ){
        for(int j = 0;j < i;j++){
            int * p1 = arr + j;
            int * p2 = arr + j + 1;
            if(*p1 > * p2){
                swap_2(p1,p2);
            }
        }
    }
}
