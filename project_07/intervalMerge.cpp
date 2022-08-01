/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-05 14:40:14
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-05 15:38:02
 * @FilePath: \learningCode\project_07\intervalMerge.cpp
 * @Description: 区间合并
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 100010;

int a[N],b[N];//前区间 后区间

/*
2
-10 -10
1 2

*/


/*
① 按区间的左端点排序
② 根据下一个区间的前后边界更新当前区间（保持不变、延迟区间、产生新区间）
*/


void test01(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        
    }

    //排序
    sort(a,a+n);
    sort(b,b+n);

    int i = 0,j = 0;//双指针
    int count = 1;//区间个数
    while(i < n-1 && j < n-1){
        if(a[j+1] <= b[j]){//存在公共区间
            j++;
        }else{
            count++;
            j++;
            i = j;
        }
    }
    cout << count << endl;


}

int main(){
    test01();

    return 0;
}