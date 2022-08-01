/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-04 15:07:39
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 16:17:43
 * @FilePath: \learningCode\project_07\doublePoint.cpp
 * @Description: 双指针算法
 */
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;

int a[N],cnt[N];//cnt用于记录当前长度内的数字出现个数

int A[N],B[N];//两个升序的数组

// int dp[N][N];//动态归化

//找出最大的不重复连续序列长度
void test01(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    } 

    int max_length = 0;
    for(int i = 0, j = 0; j < n; j++){//双指针i j
        cnt[a[j]]++;//当前数字加一
        while(cnt[a[j]] > 1){//移动前指针 i
            cnt[a[i]]--;
            i++;
        }
        //更新当前序列长度
        max_length = max(max_length,j - i + 1);
    }
    cout << max_length << endl;
    

}


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

//判断子序列
//方法一：动态归化 dp
/*
  0 1 2 3 4 5
0 0 0 0 0 0 0
1 0 1 1 1 1 1
3 0 1 1 2 2 2
5 0 1 1 2 2 3
dp[i+1][j+1] = dp[i][j] + 1; A[i] = B[j]
dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]); A[i] != B[j]

*/
// void test03(){
//     int n,m;
//     cin >> n >> m;
//     for(int i=0; i <n; i++) cin >> A[i];
//     for(int i=0; i <m; i++) cin >> B[i];

//     for(int i=0; i <n; i++){//行
//         for(int j= 0; j < m; j ++){//列
//             if(A[i] == B[j]){
//                 dp[i+1][j+1] = dp[i][j] + 1;
//             }else{
//                 dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
//             }
//             cout << dp[i][j] << " ";
//         }
//         cout << endl;
//     }

// }

//方法二：双指针
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