/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-07 17:41:57
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-07 17:45:01
 * @FilePath: \learningCode\acwing_01\acwing_829.cpp
 * @Description: 829.模拟队列
 */
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int stk[N],hh,tt;

int main(){

    hh = 0;
    tt = -1;

    int m,x;
    string str;
    cin >> m;

    while(m--){
        cin >> str;
        if(str == "push"){
            cin >> x;
            stk[++tt] = x;
        }else if(str == "pop"){
            hh++;
        }else if(str == "empty"){
            if(tt >= hh){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }else if(str == "query"){
            cout << stk[hh] << endl;
        }
    }

    return 0;
}