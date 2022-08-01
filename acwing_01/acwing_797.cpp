/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-04 14:58:20
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 15:05:20
 * @FilePath: \learningCode\acwing_01\acwing_797.cpp
 * @Description: 797.差分
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int N = 100010;

int a[N];
int s[N];

int main(){

    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = a[i] - a[i-1];
    }
    int l,r,c;
    for(int i = 0; i<m;i++){
        cin >> l >> r >> c;
        s[l] += c;
        s[r+1] -= c;
    }

    for(int i = 1; i <= n; i++){
        s[i] += s[i-1];
        cout << s[i] << " ";
    }

    return 0;
}