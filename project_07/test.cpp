/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-02 22:36:41
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 13:12:36
 * @FilePath: \learningCode\project_07\test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int N = 1e5 + 10;
int n;
int a[N];

void bubbleSort(int *a,int n,int &count){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j ++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                count++;
            }
        }
    }

}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int count = 0;

    bubbleSort(a,n,count);

    cout << count << endl;
    return 0;
}