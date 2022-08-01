/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-06-25 14:43:50
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-02 13:27:41
 * @FilePath: \learningCode\project_07\sortTest1.cpp
 * @Description: 排序算法
 */
#include<iostream>
#include<string>
using namespace std;

const int N = 1e6 + 1;//防止越界

int n;
int q[N];
int temp[N];// 归并排序需要额外的辅助数组

//交换元素位置
void swap01(int *q, int a ,int b){
    int temp = q[a];
    q[a] = q[b];
    q[b] = temp;
}

//1.快速排序
/*
案例
5
1 3 2 4 5
*/
void quickSort01(int q[],int l,int r){//l和r为左右边界

    if(l >= r) return;

    int a = l;
    int b = r;//双指针
    int ref = q[l];//第一个元素为起始元素

    while(a < b){

        //右指针移动
        while (q[b] > ref && a < b) b--;//

        //左指针移动
        while(q[a] < ref && a < b) a++;

        if(a >= b) break;//指针相遇，跳出循环

        if(q[a] == q[b] && a < b){
            b--;
        }else{
            swap01(q,a,b);
        }   
        
    }

    if(a < r) quickSort01(q,a+1,r);//右递归
    
    if(a > l) quickSort01(q,l,a-1);//左递归

    
}

//1.归并排序
/*


*/

void mergeSort01(int q[],int l,int r){
    if(l >= r) return;

    int mid = (l + r)/2;

    mergeSort01(q,l,mid);

    mergeSort01(q,mid+1,r);

    int k = 0,i = l,j = mid + 1;//k表示temp数组已经存放的个数，i为左半数组的起点，j为右半数组的起点

    //①有序地将数依次放入temp数组中，直到某一组序列为空
    while(i <= mid && j <= r){
        if(q[i] <= q[j]){
            temp[k] = q[i];
            i++;
            k++;
        }else{
            temp[k] = q[j];
            j++;
            k++;
        }
    }

    //②将剩余序列的元素填入temp数组
    while(i <= mid){
        temp[k] = q[i];
        i++;
        k++;
    }

    while(j <= r){
        temp[k] = q[j];
        j++;
        k++;
    }

    //③将temp拷贝到p数组
    for(int i = l,j = 0;i <= r;i++,j++) q[i] = temp[j];


}


int main(){
    //两种输入方式
    //1.cin
    cin >> n;
    //2.scanf 更快
    // scanf("%d",&n);

    for(int i=0; i < n ;i++){
        cin >> q[i];
    }

    mergeSort01(q,0,n-1);


    for(int i=0; i < n; i++){
        cout << q[i] << " ";
    }
    cout << endl;



    return 0;
}