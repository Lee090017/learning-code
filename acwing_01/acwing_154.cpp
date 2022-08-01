/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-09 17:24:33
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-09 18:58:05
 * @FilePath: \learningCode\acwing_01\acwing_154.cpp
 * @Description: 154.滑动窗口
 */
#include<iostream>
#include<queue>
using namespace std; 

const int N = 1e6 + 10;

/*
8 3
1 3 -1 -3 5 3 6 7

解析：
单调递增队列 q
i = 0
q: 1

i = 1 ,且 a[1] > q[tt]
q: 1 3

i = 2 , q[tt] > a[2]                <=====   实际上当前为第一个窗口，因为 i+1 = k
q: -1

i = 3 , q[tt] > a[3]
q: -3
....
q: -3 5
....
q: -3 3

i = 6 , i - 3 + 1 = 4 > k = 3 
i为6时，最小值-3的下标已经超出了窗口的范围，因此队列q的队头出队列
q: 3 6
.....
q: 3 6 7

最小值： -1 -3 -3 -3 3 3
最大值： 3 3 5 5 6 7
*/

int a[N],q[N];//单调队列q 存数组的下标 q[hh]表示当前最小的元素 (单调递增队列)

int hh,tt;

int n,k;//n个数，k的窗口

void printQueue(){
    for(int i = hh; i <= tt; i++){
        cout << a[q[i]] << "=";
    }
    cout << endl;
}

int main() {

    scanf("%d%d",&n,&k);

    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    hh = 0,tt = -1;//初始化
    //最小值
    for(int i = 0; i < n; i++){//第k个窗口
        //队列不为空 第i个窗口与最小值的坐标 距离超出窗口
        if(hh <= tt && q[hh] < i - k +1) hh++;//队首的最小元素出队列
        //当 队尾元素 大于 当前元素时,队尾一定不是最小元素，将队尾元素出队列
        while(hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;//当前元素入队列
        // printQueue();
        if(i+1 >= k) cout << a[q[hh]] << " ";//从 k-1个数开始算第一个窗口
    }
    cout << endl;

    //最大值
    hh = 0,tt = -1;
    for(int i = 0; i < n; i++){
        if(hh <= tt && q[hh] < i - k +1) hh++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;//改变单调队列的单调性
        q[++tt] = i;
        if(i+1 >= k) cout << a[q[hh]] << " ";
    }
    
    return 0;
}