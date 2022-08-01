/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-07 16:10:37
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-07 16:21:12
 * @FilePath: \learningCode\project_08\stack.cpp
 * @Description: 栈 和 队列
 */
#include<iostream>

using namespace std;

const int N = 100010;

int stk[N],tt;//tt表示栈顶的元素

//1.栈

//入栈 stk[ ++ tt] = x;

//出栈 tt --;

//栈是否为空 if(tt > 0) 不为空

//得到栈顶元素 stk[tt]

//***************************************

//2.队列

int q[N],hh,tt = -1;//hh表示队头 tt表示队尾

//入队列 q[++t] = x;

//弹出 hh++;

//判断空 if(hh <= tt) not empty

//取队头q[hh] q[tt]

int main(){

    return 0;
}