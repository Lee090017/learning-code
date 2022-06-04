/*
 * @Author: your name
 * @Date: 2022-05-25 17:07:10
 * @LastEditTime: 2022-05-26 15:40:18
 * @LastEditors: Lee090017 455938969@qq.com
 * @Description: 复习deque stack queue
 * @FilePath: \learningCode\project_05\reviewTest2.cpp
 */
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
using namespace std;

class Person{
public:
    Person(){

    }

    Person(string name,int score){
        this->name = name;
        this->score = score;
    }

    string name;
    int score;

};


void printDeque(deque<int> & d){
    for(deque<int>::iterator it = d.begin(); it != d.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * @brief 
 * 复习deque数组
 * 双端数组，对头尾进行插入删除操作
 * 
 */
void test01(){
    deque<int> d1;
    for(int i = 0; i <10;i++){
        d1.push_back(i);
    }
    deque<int> d2;
    d2.assign(d1.begin(),d1.end());
    printDeque(d2);

    d2.resize(5);
    d2.resize(10);

    //deque无容量函数
    printDeque(d2);
    cout << "size is " <<d2.size() << endl;

    deque<int>::iterator it = d2.begin();
    d2.insert(it+3,2,10);
    printDeque(d2);
    d2.erase(it+3,it+5);
    printDeque(d2);

    for(int i=0;i<d2.size();i++){
        cout << d2[i] << "-";
    }
    cout << endl;

    //排序，使用时包含algorithm
    sort(d2.begin(),d2.end());
    printDeque(d2);

}

/**
 * @brief 
 * 测试stack栈
 * 先进后出
 * 
 */
void test02(){
    stack<int> s1;

    for(int i = 0; i <10;i++){
        s1.push(i);
    }

    while(!s1.empty()){
        cout << "top is " << s1.top() << endl;
        s1.pop();
    }

}

/**
 * @brief 
 * 复习queue队列
 * 先进先出
 * 
 */
void test03(){
    queue<int> q1;
    for(int i=0; i <5;i++){
        q1.push(i);
    }
    while(q1.size()>0){
        cout<< "front is " << q1.front() << endl;
        q1.pop();
    }
}

int main(){
    test03();

    return 0;
}