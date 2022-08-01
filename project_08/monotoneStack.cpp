/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-09 13:20:46
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-09 13:32:45
 * @FilePath: \learningCode\project_08\monotoneStack.cpp
 * @Description: 单调栈
 */
#include <iostream>

using namespace std;

//输出每个数左边第一个比它小的数
/*
5
3 4 2 7 5

-1 3 -1 2 2
*/

const int N = 100010;

int stk[N],tt;

int main(){
    int n,t;
    cin >> n;

    //栈初始化
    tt = 0;
    stk[0] = -1;

    while (n--)
    {
        cin >> t;//当前输入的元素

        while(tt > 0 && stk[tt] >= t){
            tt--;
        }
        cout << stk[tt] << " ";
        stk[++tt] = t;//入栈
    }
    

    return 0;
}