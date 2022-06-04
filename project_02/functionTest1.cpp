/*
 * @Author: your name
 * @Date: 2022-04-12 15:37:38
 * @LastEditTime: 2022-04-12 16:03:24
 * @LastEditors: Please set LastEditors
 * @Description: 函数的高级用法
 * @FilePath: \learningCode\project_02\functionTest1.cpp
 */

#include<iostream>
using namespace std;

//函数的默认参数
int func(int a,int b = 20,int c = 30){
    return (a+b+c);
}
/*
注意事项：
    1.如果某个地方有默认值，从左到右都必须有默认参数
    2.如果函数声明有默认参数，那函数实现就不能有默认参数

*/

int func2(int a = 10,int b = 20);

int func2(int a,int b){//函数的默认参数不能具有二义性
    return a + b;
}

//函数占位参数
int func3(int a,int){//必须传入占位参数
    return a + 10;
}

//函数重载条件：
/*
    1.同一作用域
    2.函数名相同
    3.函数的形参列表不同
    4.函数的返回值不能作为重载的条件


*/
// string func3(int a){
//     return "int a is used";
// }

//引用作为重载的条件
string func3(int &a){
    return "int & a is used";
}

string func3(const int &a){
    return "const int & a is used";
}


int main(){

    cout << func(10,30) << endl;//如果传入数据，用传入数据，否则用默认值
    int a = 10;
    cout << func3(a) << endl;
    cout << func3(10) << endl;
    return 0;
}
