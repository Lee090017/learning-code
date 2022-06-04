/*
 * @Author: your name
 * @Date: 2022-04-28 20:30:15
 * @LastEditTime: 2022-04-29 17:36:42
 * @LastEditors: Please set LastEditors
 * @Description: deque容器
 * @FilePath: \learningCode\project_05\dequeTest.cpp
 */

/**
 * @file dequeTest1.cpp
 * @author your name (you@domain.com)
 * @brief 双端数组，可以对头端进行插入删除操作
 * @version 0.1
 * @date 2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
/**
 * @brief 
 * 
 * deque对于头部的插入删除速度比vector快
 * vector访问元素时的速度比deque快
 * 
 * 内部工作原理：内部的中控器，维护每段缓冲区中的内容，缓冲区存放真实数据
 * 
 * 支持随机访问
 */

void printDeque(const deque<int> &d){
    if(d.empty()){
        cout << "deque is empty" << endl;
        return;
    }
    //容器中需要使用const迭代器
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * @brief 
 * 
 * deque构造函数
 * 
deque<T> deqT; //默认构造形式
deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem); //构造函数将n个elem拷贝给本身。
deque(const deque &deq); //拷贝构造函数

补充：
deque(n); //初始化deque，包含n个0元素
以下初始化也可以：
① deque<int> deque = {1,2,3,4};
② deque<int> deque{1,2,3,4};
③ deque<int> deque({1,2,3,4});
 */

void test01(){
    deque<int> d1;
    for(int i = 0; i <10;i++){
        d1.push_back(i);
    }

    printDeque(d1);

    deque<int> d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int> d3(10,100);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);

}

/**
 * @brief 
 * 
 * deque赋值
 * 
deque& operator=(const deque &deq); //重载等号操作符
assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem); //将n个elem拷贝赋值给本身。
 */

void test02(){
    deque<int> d1;
    for(int i = 0; i <10;i++){
        d1.push_back(i);
    }

    deque<int> d2 = d1;
    printDeque(d2);

    deque<int> d3;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(10,100);
    printDeque(d4);
}

/**
 * @brief 
 * 
 * deque大小操作
 * 
deque.empty(); //判断容器是否为空
deque.size(); //返回容器中元素的个数
deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
​ //如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
​ //如果容器变短，则末尾超出容器长度的元素被删除。
 */

void test03(){

    //deque容器没有容量的限制
    deque<int> d1;
    if(d1.empty()) cout<<"deque is empty"<<endl;

    for(int i = 0; i <10;i++){
        d1.push_back(i);
    }

    cout << "deque's size is " << d1.size() << endl;

    d1.resize(3);
    d1.resize(5,88);
    printDeque(d1);

}

/**
 * @brief 
 * 
 * deque插入和删除
 * 
两端插入操作：
push_back(elem); //在容器尾部添加一个数据
push_front(elem); //在容器头部插入一个数据
pop_back(); //删除容器最后一个数据
pop_front(); //删除容器第一个数据

指定位置操作：
insert(const_iterator pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(const_iterator pos,n,elem); //在pos位置插入n个elem数据，无返回值。
insert(const_iterator pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。
clear(); //清空容器的所有数据
erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置。
erase(const_iterator pos); //删除pos位置的数据，返回下一个数据的位置。
 */

void test04(){
    deque<int> d1;
    d1.push_back(5);
    d1.push_front(4);
    d1.push_back(6);
    d1.push_front(3);

    printDeque(d1);

    d1.pop_front();
    d1.pop_back();

    printDeque(d1);

    d1.insert(d1.begin(),3,3);//头部插入3个3

    printDeque(d1);

    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(),d2.begin(),d2.end());//在d1的起始插入d2的区间
    printDeque(d1);

    deque<int>::iterator it = d1.begin();
    d1.erase(it+3,it+5);
    printDeque(d1);

    d1.clear();
    printDeque(d1);


}

/**
 * @brief 
 * 
 * deque数据存取
 * 
at(int idx); //返回索引idx所指的数据
operator[]; //返回索引idx所指的数据
front(); //返回容器中第一个数据元素
back(); //返回容器中最后一个数据元素
 */

void test05(){
    deque<int> d1;
    for(int i = 0; i <10;i++){
        d1.push_back(i);
    }

    cout << "d1[0] = " << d1[0] << endl;

    cout << "d1.at(5) = " << d1.at(5) << endl;

    cout << "d1.front() = " << d1.front() << endl;

    cout << "d1.back() = " << d1.back() << endl;
}

/**
 * @brief 
 * 
 * deque排序
 * 
sort(iterator beg, iterator end) //对beg和end区间内元素进行排序
 */
void test06(){
    deque<int> d1;
    for(int i = 9; i >=0;i--){
        d1.push_back(i);
    }

    deque<int>::iterator it = d1.begin();
    //对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
    //vector容器也可以利用sort进行排序
    sort(it+1, it+8);//默认从小到大  需要包含头文件algorithm
    printDeque(d1);

}

int main(){
    test06();

    return 0;
}