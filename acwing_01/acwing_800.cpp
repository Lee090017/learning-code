/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-04 15:40:50
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 15:40:55
 * @FilePath: \learningCode\acwing_01\acwing_800.cpp
 * @Description: 800.数组元素的目标和
 */
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;

int A[N],B[N];//两个升序的数组

//求两个升序排列的有序数组的唯一一组目标和
void test02(){
    int n,m,x;
    cin >> n >> m >> x;
    for(int i=0; i <n; i++) cin >> A[i];
    for(int i=0; i <m; i++) cin >> B[i];
    
    int i = 0,j = m-1;//头指针 和 尾指针
    while(i < n && j >= 0){
        if(A[i] + B[j] == x){
            cout << i << " " << j << endl;
            return;
        }else if(A[i] + B[j] > x){
            j--;
        }else i++;
    }

}


int main(){
    test02();

    return 0;
}