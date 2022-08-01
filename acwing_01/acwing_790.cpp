/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-04 14:15:12
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 14:33:50
 * @FilePath: \learningCode\acwing_01\acwing_790.cpp
 * @Description: 790.数的三次方根
 */
#include<iostream>

using namespace std;

int main(){

    double n;
    cin >> n;

    double l = -100,r = 100;
    // if(n >= 0 ) l = -n,r = n;
    // else l = n,r = -n;
    while(r - l > 1e-7){
        double x = (l + r)/2;
        if(x*x*x >= n) r = x;
        else l = x;
    }

    printf("%.6f\n",l);


    return 0;
}