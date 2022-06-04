/*
 * @Author: your name
 * @Date: 2022-04-29 15:48:58
 * @LastEditTime: 2022-04-29 15:56:46
 * @LastEditors: Please set LastEditors
 * @Description: queue容器
 * @FilePath: \learningCode\project_05\queueTest1.cpp
 */
#include<iostream>
#include<string>
#include<queue>
using namespace std;

//先进先出 只有队头和队尾能被外界访问，因此不允许有遍历行为
// 队列容器允许从一端新增元素，从另一端移除元素
// 队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
// 队列中进数据称为 — 入队 push
// 队列中出数据称为 — 出队 pop

/**
 * 
构造函数：
queue<T> que; //queue采用模板类实现，queue对象的默认构造形式
queue(const queue &que); //拷贝构造函数

赋值操作：
queue& operator=(const queue &que); //重载等号操作符

数据存取：
push(elem); //往队尾添加元素
pop(); //从队头移除第一个元素
back(); //返回最后一个元素
front(); //返回第一个元素

大小操作：
empty(); //判断堆栈是否为空
size(); //返回栈的大小
 */

void test01(){
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    cout << "back = " << q1.back() << endl;

    while(!q1.empty()){
        int f = q1.front();
        cout << "front = " << f << endl;
        q1.pop();
    }

    cout << "size = " << q1.size() << endl;

}

int main(){

    test01();


    return 0;

}