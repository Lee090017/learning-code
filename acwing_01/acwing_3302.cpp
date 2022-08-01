/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-07 16:24:03
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-07 17:41:15
 * @FilePath: \learningCode\acwing_01\acwing_828.cpp
 * @Description: 3302.表达式求值
 */
#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

// const int N = 100010;

// char stk[N];

/*
(1+1)*(2+2)

nums 1 1
opt  ( +
====> )

1 + 1 = 2
nums 2 2 2
opt  * ( + 
====> )

2 + 2 = 4
nums 2 4
opt *

===> 2 * 4 = 8
*/

//定义符号的优先级
map<char,int> h{{'+',1},{'-',1},{'*',2},{'/',2}};

stack<int> nums;//数栈
stack<char> opt;//符号栈

//计算栈顶元素的值，并入栈
void eval(){
    int a = nums.top();
    nums.pop();

    int b = nums.top();
    nums.pop();

    char c = opt.top();
    opt.pop();

    int r = 0;

    if(c == '+') r = a + b;
    if(c == '-') r = b - a;
    if(c == '*') r = a * b;
    if(c == '/') r = b / a;

    nums.push(r);
}

int main(){

    string str;
    cin >> str;
    //将表达式变为数组
    for(int i=0; i < str.size(); i++){
        //判断数还是符号
        if(str[i] -'0' >= 0 && str[i] - '0' <= 9){
            //将一串数字入栈
            int x = 0;
            while(i < str.size() && isdigit(str[i])){
                x = x * 10 + str[i] - '0';
                i++;
            }
            nums.push(x);
            i--;

        }else if(str[i] == '('){//左括号直接入栈
            opt.push(str[i]);
        }else if(str[i] == ')'){//右括号计算括号内部值
            while (opt.top()!='(')
            {
                eval();
            }
            opt.pop();
        }else{//根据符号优先级入栈
            //如果栈顶符号的优先级大于等于入栈的符号，先计算再入栈
            while(!opt.empty() && h[opt.top()] >= h[str[i]]){
                eval();
            }
            opt.push(str[i]);//操作符入栈

        }
        
    }

    //计算栈中剩余操作
    while(!opt.empty()) eval();
    cout << nums.top() << endl;

    

    return 0;
}