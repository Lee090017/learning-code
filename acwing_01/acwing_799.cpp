/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-04 15:07:06
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 15:27:39
 * @FilePath: \learningCode\acwing_01\acwing_799.cpp
 * @Description: 799.最长连续不重复子序列
 */
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;

int a[N],cnt[N];//cnt用于记录当前长度内的数字出现个数

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

int main(){
    test01();

    return 0;
}