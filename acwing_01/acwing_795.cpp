/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-04 14:55:23
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 14:56:35
 * @FilePath: \learningCode\acwing_01\acwing_795.cpp
 * @Description: 795.前缀和
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int N = 100010;

int a[N];

int main(){

    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    int l,r;
    for(int i = 0; i<m;i++){
        cin >> l >> r;
        cout << a[r] - a[l-1] << endl;
    }

    return 0;
}