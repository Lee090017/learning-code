/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-02 22:36:41
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 13:36:47
 * @FilePath: \learningCode\project_07\test.cpp
 * @Description: 788.求 逆序对 的数量
 */
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
 
const int N = 1e5 + 10;
int n;
int a[N];
int temp[N];

LL mergeSort(int q[],int l,int r){
    if(l >= r) return 0;

    int mid = (l + r)/2;

    LL res = mergeSort(q,l,mid) + mergeSort(q,mid+1,r);

    int k = 0,i = l,j = mid + 1;//k表示temp数组已经存放的个数，i为左半数组的起点，j为右半数组的起点

    //①有序地将数依次放入temp数组中，直到某一组序列为空
    while(i <= mid && j <= r){
        if(q[i] <= q[j]){
            temp[k++] = q[i++];
        }else{
            temp[k++] = q[j++];
            res += mid - i + 1;
        }
    }

    //②将剩余序列的元素填入temp数组
    while(i <= mid){
        temp[k++] = q[i++];
    }

    while(j <= r){
        temp[k++] = q[j++];
    }

    //③将temp拷贝到p数组
    for(int i = l,j = 0;i <= r;i++,j++) q[i] = temp[j];

    return res;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    LL count = mergeSort(a,0,n-1);

    cout << count << endl;
    return 0;
}