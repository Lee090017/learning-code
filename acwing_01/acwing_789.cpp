/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-04 13:55:12
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 14:13:57
 * @FilePath: \learningCode\acwing_01\acwing_789.cpp
 * @Description: 789.数的范围
 * 
 *
 * 示例
6 3
1 2 2 3 3 4
3
4
5
 */

#include<iostream>

using namespace std;

const int N = 100010;
int a[N];

int main(){
    int n,q;
    scanf("%d%d",&n,&q);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0; i < q; i++){
        int k;
        cin >> k;
        //前二分查找  [l,mid]
        int l = 0,r = n-1;
        while (l < r)
        {
            int mid = r + l >> 1;
            if(a[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if(a[l] != k) cout << "-1 -1" << endl;
        else{
            //后二分查找[mid,r]
            cout << l << " ";
            r = n-1;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(a[mid] > k) r = mid - 1;
                else l = mid;
            }
            cout << r << endl;
        }
        
    
    }
    

    return 0;
}