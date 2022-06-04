/*
 * @Author: your name
 * @Date: 2022-04-29 15:33:13
 * @LastEditTime: 2022-04-29 15:48:24
 * @LastEditors: Please set LastEditors
 * @Description: stack容器
 * @FilePath: \learningCode\project_05\stackTest1.cpp
 */
#include<iostream>
#include<stack>
#include<string>
using namespace std;

//先进后出 不允许遍历算法，只有栈顶才能被访问
//栈也可以判断是否为空，可以得到元素的个数

/** @
 * 栈的构造函数
 * 
 构造函数：
stack<T> stk; //stack采用模板类实现， stack对象的默认构造形式
stack(const stack &stk); //拷贝构造函数

赋值操作：
stack& operator=(const stack &stk); //重载等号操作符

数据存取：
push(elem); //向栈顶添加元素
pop(); //从栈顶移除第一个元素
top(); //返回栈顶元素

大小操作：
empty(); //判断堆栈是否为空
size(); //返回栈的大小
 * 
 * 
 * 
 * 
 */

void test01(){
    stack<int> s1;

    //入栈
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    //出栈
    while(!s1.empty()){
        int temp = s1.top();
        cout << "s1 top = " << s1.top() << endl;
        s1.pop();
    }

    cout << "s1 size = " << s1.size() << endl;



}

int main(){

    test01();

    return 0;
}