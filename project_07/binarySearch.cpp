/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-02 13:33:39
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-02 15:36:01
 * @FilePath: \learningCode\project_07\binarySearch.cpp
 * @Description: 二分搜索
 */
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n,q;//n表示n个整数，q表示q个查询

int a[N];

//二分查找
/*案例
输入：
13 3
1 2 2 2 2 2 3 3 3 3 3 3 4
3
4
5
输出：
3 4
6 11
-1 -1
*/
//搜索数据存在位置，如需要定位重复的该元素位置，需要从该索引向两端扫描
int binarySearch01(int q[],int l,int r,int s){
    if(l > r) return -1;

    int mid = (l + r)>>1;//(l + r)/2
    int midVal = q[mid];

    if(midVal > s){
        binarySearch01(q,l,mid-1,s);
    }else if(midVal < s){
        binarySearch01(q,mid+1,r,s);
    }else{
        return mid;
    }

}


//用二分法表示一个浮点数的平方根，精度 10^-6
void doubleBinarySearch(){

    double x;
    cin >> x;
    double l = 0,r = x;

    //
    while (r - l > 1e-6)
    {
        double mid = (l + r)/2;
        if(mid * mid >= x)  r = mid;
        else l = mid;
    }
    printf("%f\n",l);
    return;
}



int main(){

    //浮点数的精度
    // doubleBinarySearch();

    cin >> n >> q;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    int s;
    for(int i = 0; i < q; i++){
        cin >> s;

        //本算法提供方法：定位左边第一个出现的元素位置，和右边出现的第一个元素位置
        int l = 0,r = n-1;
        //确定左边界
        while(l < r){
            int mid = (l + r) >> 1;
            if(a[mid] >= s) r = mid;
            else l = mid + 1;//左边界向后移动一小格
        }
        if(a[l] != s) cout << "-1 -1"<< endl;
        //确定右边界
        else{
            cout << l << " ";
            r = n - 1;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(a[mid] <= s) l = mid;
                else r = mid - 1;
            }
        }
        cout << l << endl;
        
    }

    return 0;
}