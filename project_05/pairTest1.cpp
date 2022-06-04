/*
 * @Author: your name
 * @Date: 2022-04-29 18:49:19
 * @LastEditTime: 2022-04-29 18:55:07
 * @LastEditors: Please set LastEditors
 * @Description: pair对组
 * @FilePath: \learningCode\project_05\pariTest1.cpp
 */
/**
 * 
 * 成对出现的数据，利用对组可以返回两个数据

 * 
 * 两种创建方式：

pair<type, type> p ( value1, value2 );
pair<type, type> p = make_pair( value1, value2 );

*/
#include<iostream>
#include<string>
using namespace std;

void test01(){
    pair<int, string> p1(1,"lee");//创建对组

    cout << p1.first << " " << p1.second << endl;

    pair<int, string> p2 = make_pair(2,"wang");

    cout << p2.first << " " << p2.second << endl;


}

int main(){

    test01();

    return 0;
}