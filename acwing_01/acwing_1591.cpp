/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-06-25 16:54:42
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-06-25 17:45:45
 * @FilePath: \learningCode\project_07\example.cpp
 * @Description: Acwing_1591. 快速排序
 */
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

const int N = 1e5 + 1;//防止越界

int n;
int q[N];
int sum = 0;
int pre_max[N];
int be_min[N];
vector<int> v;

/*
20
4 193 187 23 183 48 72 11 123 164 148 155 160 146 168 27 77 188 9 199
*/

int main(){

    cin >> n;

    for(int i=0; i < n ;i++){
        cin >> q[i];
        //获取前数组最大值
        if(i == 0){
            pre_max[i] = 0;
        }else{
            if(q[i-1] > pre_max[i-1]){
                 pre_max[i] = q[i-1];
            }else{
                 pre_max[i] = pre_max[i-1];
            }
        }      
    }

    //获取后数组最小值
    for(int i=n-1; i >= 0 ;i--){
        if(i == n-1){
            be_min[i] = INT_MAX;
        }else{
            if(q[i+1] < be_min[i+1]){
                 be_min[i] = q[i+1];
            }else{
                 be_min[i] = be_min[i+1];
            }
        }  
    }

    for(int i=0; i < n; i++){
        if(q[i] > pre_max[i] && q[i] < be_min[i]){
            sum++;
            v.push_back(q[i]);
        }
    }

    cout << sum << endl;

    for(vector<int>::iterator it=v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;


    return 0;
}