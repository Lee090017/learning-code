/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-09 13:37:03
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-09 14:56:08
 * @FilePath: \learningCode\acwing_01\acwing_1574.cpp
 * @Description: 接雨水
 */
#include <iostream>
#include <stack>
using namespace std;

typedef pair<int, int> PII;//存放下标和数据

const int N = 1010;

stack<PII> stk,buff;//stk 单调递增栈 buff 缓存单调递减栈

/*
12
0 1 0 2 1 0 1 3 2 1 2 1

6
*/

int main(){
    int n,t;
    cin >> n;
    int i = 0;//下标初始值
    
    int sum= 0;//积水总量
    while(n--){
        cin >> t;
        int j = 0;
        while(!stk.empty() && stk.top().second <= t){
            if(buff.empty()) j = stk.top().first;//记录buff栈底元素下标
            //出栈
            buff.push(stk.top());
            stk.pop();
        }
        stk.push({i++,t});//入栈
        //统计积水数量
        while(!buff.empty()){
            auto f = buff.top();
            buff.pop();
            if(!buff.empty()){
                sum += (j - f.first) * (f.second - buff.top().second);
            }
        }
    }
    cout << sum << endl;

    return 0;
}