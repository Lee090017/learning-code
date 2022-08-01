/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-07 16:24:03
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-07 16:30:21
 * @FilePath: \learningCode\acwing_01\acwing_828.cpp
 * @Description: 828.模拟栈
 */
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int stk[N],tt;

int main(){

    tt = 0;

    int m,x;
    string str;
    cin >> m;

    while(m--){
        cin >> str;
        if(str == "push"){
            cin >> x;
            stk[++tt] = x;
        }else if(str == "pop"){
            tt--;
        }else if(str == "empty"){
            if(tt > 0){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }else if(str == "query"){
            cout << stk[tt] << endl;
        }
    }

    return 0;
}