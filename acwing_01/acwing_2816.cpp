/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-04 16:01:15
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 16:18:01
 * @FilePath: \learningCode\acwing_01\acwing_2816.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;

int A[N],B[N];//两个升序的数组

void test03(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i <n; i++) cin >> A[i];
    for(int i=0; i <m; i++) cin >> B[i];

    int i = 0,j = 0;
    while(i < n && j < m){
        if(A[i] != B[j]){//b序列后移
            j++;
        }else{
            i++;
            j++;
        }
        if(i == n){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main(){
    test03();

    return 0;
}