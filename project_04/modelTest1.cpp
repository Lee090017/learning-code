/*
 * @Author: your name
 * @Date: 2022-04-25 15:16:51
 * @LastEditTime: 2022-04-26 21:28:41
 * @LastEditors: Please set LastEditors
 * @Description: 模板---函数模板
 * @FilePath: \learningCode\project_04\modeTest.cpp
 */

/**
 * @file modeTest.cpp
 * @author your name (you@domain.com)
 * @brief 泛型编程
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * 语法：
 * template<typename T>
 * 函数声明或定义
 * template --申明创建模板
 * typename --表明其后面是一种数据类型，可以用class代替
 * T --通用数据类型，名称可以替换，通常为大写字母
 * 
 * 注意事项：
 * 1.自动类型推导需要推导出一致数据类型，才能使用 mySwap(int,char)推导不出一致的类型
 * 2.模板必须确定T的数据类型才能使用 func<int>() 无形参时，确定数据类型才能使用
 * 
 * 
 * 普通函数和函数模板的区别
 * 普通函数可以发生自动类型转换
 * 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换，但是指定类型时可以
 * 
 */
#include<iostream>
using namespace std;

//案例
void swapInt(int &a,int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapDouble(double &a,double &b) {
    double temp = a;
    a = b;
    b = temp;
}

//函数模板
template<typename T> //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是通用数据类型 typename可以替换为class
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

//普通函数和函数模板
int myAdd01(int a, int b){
    return a + b;
}

template<class T>
T myAdd02(T a, T b){
    return a + b;
}

template<class T>
//从大到小
void quickSort(T arr[]){
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        T max = arr[i];
        int index = i;
        for(int j=i; j<sizeof(arr); j++){
            if(arr[j] > max){
                max = arr[j];
                index = j;
            }
        }
        //交换位置
        T temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

//普通函数和函数模板的调用规则
//优先调用普通函数，使用空模板参数列表调用函数模板，函数模板可以重载
void myPrint(int a,int b){
    cout << "调用普通函数" << endl;
}

template<typename T>
void myPrint(T a,T b){
    cout << "调用函数模板" << endl;
}

template<typename T>
void myPrint(T a,T b,T c){
    cout << "调用重载的函数模板" << endl;
}

void test01(){
    //两种方式使用函数模板
    //1.自动类型推导
    int a = 1;
    int b = 2;
    // mySwap(a, b);
    //2.显示指定类型
    mySwap<int>(a, b);//指定T为int数据类型
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}

void test02(){
    // int a[5] = {0,2,1,-3,5};
    char a[5] = {'c','a','b','e','d'};
    quickSort(a);
    //打印数组
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
        cout << a[i] << " " ;
    }
    cout << endl;
}

void test03(){
    int a = 10;
    int b = 20;
    char c = 'a';
    cout << a << "+" << c << "=" << myAdd01(a,c) <<endl;//发生隐式类型转换

    //自动类型推导
    cout << a << "+" << b << "=" << myAdd02(a,b) <<endl;//不发生隐式类型转换
    //显示指定类型
    cout << a << "+" << c << "=" << myAdd02<int>(a,c) <<endl;//发生隐式类型转换
}

void test04(){
    int a = 1000;//
    int b = 2000;
    myPrint(a,b);//调用普通函数
    //空模板的参数列表
    myPrint<>(a,b);//强制调用模板
    myPrint(a,b,10);
    //函数模板产生更好的匹配
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1,c2);//无需进行隐式内存转换
}

int main(){
    // test01();
    // test02();
    // test03();
    // test04();
    
    return 0;
}