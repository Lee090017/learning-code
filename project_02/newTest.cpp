/*
 * @Author: your name
 * @Date: 2022-04-11 21:41:45
 * @LastEditTime: 2022-04-11 21:50:50
 * @LastEditors: Please set LastEditors
 * @Description: new 的使用
 * @FilePath: \learningCode\project_02\newTest.cpp
 */

#include<iostream>
using namespace std;

int * func_3(){

    int * p = new int(10);
    return p;
}

//new 创建数组
int * func_4(){

    int * arr = new int[10];//返回数组首地址
    for(int i = 0; i < 10;i++){
        arr[i] = i+100;
    }
    return arr;
}

int main(){

    int * p = func_3();
    cout << *p << endl;//解引用
    cout << *p << endl;
    cout << *p << endl;
    //堆区的数据由程序员管理开辟和释放
    //如果想释放需要利用delete关键字
    delete p;
    cout << *p << endl;
    cout << *p << endl;

    int * arr = func_4();
    for (int i = 0;i<10;i++){
        cout << arr[i] << endl;
    }
    delete [] arr;//释放数组时需要加[]才行
    for (int i = 0;i<10;i++){
        cout << arr[i] << endl;
    }

    return 0;
}
