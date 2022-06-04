/*
 * @Author: your name
 * @Date: 2022-04-12 14:57:49
 * @LastEditTime: 2022-04-12 15:35:39
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \learningCode\project_02\referenceTest.cpp
 */
/**
 * @file referenceTest.cpp
 * @author your name (you@domain.com)
 * @brief 引用的用法
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * 给变量取别名
 * 
 * 语法： 数据类型 &别名 = 原名
 * 
 * 注意事项：引用必须初始化，引用初始化后不能修改
 * 
 */
#include<iostream>
using namespace std;

//引用做函数参数
//函数传参时，可以利用引用的技术让形参修饰实参，可以简化指针修改实参
//引用的本质是一个指针常量 int * const ref = &a;

//值传递
void mySwap01(int a,int b){
    int temp = a;
    a = b;
    b = temp;
}

//地址传递
void mySwap02(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//引用传递
void mySwap03(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

//引用做函数的返回值
//不要返回局部变量的引用
int & test01(){
    int a = 10;
    return a;
}

//函数的调用可以作为左值
int & test02(){
    static int a = 10;//全局数据在程序执行后释放
    return a;
}

//常量引用
//用来修饰形参防止误操作
void showValue(const int & value){
    cout << "value = " << value << endl;
}


int main(){

    int a = 10;
    //int &b;//错误
    int &b = a;//为变量a取别名
    b = 20;
    cout << "a = " << a << endl;

    int c = 30;
   //b = c;//赋值操作，不允许更改引用操作
    mySwap01(a,c);
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
    cout << "====================" << endl;
    mySwap02(&a,&c);
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
    cout << "====================" << endl;
    mySwap03(a,c);
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
    cout << "====================" << endl;
    // int &ref1 = test01();
    // cout << "ref1 = " << ref1 << endl;
    int &ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    test02() = 1000;//返回的是原名
    cout << "ref2 = " << ref2 << endl;//可以将函数的返回值作为左值进行赋值

    //创建临时变量temp存放10，再将temp赋值给ref
    const int &ref = 10;//常量引用，只读不能修改
    showValue(123);


    return 0;
}