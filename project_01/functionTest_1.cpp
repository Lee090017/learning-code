/*
 * @Author: your name
 * @Date: 2022-04-06 21:03:07
 * @LastEditTime: 2022-04-06 21:42:50
 * @LastEditors: Please set LastEditors
 * @Description: 函数
 * @FilePath: \learningCode\project_01\functionTest.cpp
 */
/*
    函数的书写步骤
        1.返回值类型
        2.函数名
        3.参数表列
        4.函数体语句
        5.return表达式

    函数的调用

    函数的常见样式
    1.无参无返
    2.有参无返
    3.无参有返
    4.有参有返


*/
#include<iostream>
using namespace std;

//无声明，定义在开头
int add(int a,int b){//形参列表
    int sum = a + b;
    return sum;
}

void swap_(int a,int b){//形参列表
    int temp = a;
    a = b;
    b = temp;
}

//有申明
int max(int a,int b);//申明可以多次，但是定义只能一次

int main(){

    int res_sum = add(1,2);
    cout << res_sum << endl;

    int a = 1;
    int b = 2;
    swap_(a,b); //值传递时，形参发生改变不会影响实参
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "The max num is " << max(a,b) << endl;
    return 0;
}

int max(int a,int b){
    return a > b ? a:b;
}