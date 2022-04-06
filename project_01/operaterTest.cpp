/*
 * @Author: your name
 * @Date: 2022-04-06 16:08:06
 * @LastEditTime: 2022-04-06 16:20:29
 * @LastEditors: Please set LastEditors
 * @Description: 运算符
 * @FilePath: \learningCode\project_01\operaterTest.cpp
 */
#include<iostream>
using namespace std;
int main(){
    //加减乘除
    int a = 2;
    int b = 3;
    cout << a / b << endl;

    //递增递减运算
    int a1 = 1;
    int b1;
    b1 = a1++;
    cout << a1 << endl; //2
    cout << b1 << endl; //1

    //赋值运算
    int a2 = 1;
    cout << (a1+=2) << endl;

    //比较运算
    if(a1 != a2){
        cout << "a1 ~= a2" << endl;
    }
    
    //逻辑运算
    bool flag1 = 1;
    cout << !flag1 << endl;

    return 0;
}
