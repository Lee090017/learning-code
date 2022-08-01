/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-05 11:26:35
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-05 14:39:10
 * @FilePath: \learningCode\project_07\discretization.cpp
 * @Description: 离散化 将稀疏矩阵映射到新的坐标上
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;

const int N = 300010;

int a[N],s[N];// a 为离散化后的数组 s为前缀和

vector<int> p;//需要离散的点的位置
vector<PII> o,q;//o为操作，q为查询

//返回数组中元素的坐标位置,二分查找
int find(vector<int> & v,int x){
    int l = 0,r = v.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if(v[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return  l + 1;
}

/*
3 3
1 2
3 6
7 5
1 3
4 6
7 8

8
0
5
*/
//将输入的两组数据在坐标轴上离散化
void test01(){
    int n,m;//n次操作 m次询问
    cin >> n >> m;

    int x,c,l,r;
    for(int i=0;i<n;i++){
        cin >> x >> c;
        p.push_back(x);
        o.push_back({x,c});
    }

    for(int i = 0; i < m ; i++){
        cin >> l >> r;
        p.push_back(l);
        p.push_back(r);
        q.push_back({l,r});
    }

    //将所有离散点去重并排序，这里使用STL中的unique函数
    sort(p.begin(), p.end());//排序
    p.erase(unique(p.begin(), p.end()),p.end());//去重
    
    //p数组的下标+1为映射到数组a[N]的实际位置
    //根据 操作o 对 数组a 的数字进行添加
    for(auto i : o){
        int t = find(p,i.first);
        a[t] += i.second;
    }


    //得到前缀和数组
    for(int i = 1; i <= p.size(); i++){
        s[i] = s[i-1] + a[i];
    }

    //计算查询范围的前缀和之差
    for(auto i : q){
        int x = find(p,i.first);
        int y = find(p,i.second);//映射到新的坐标
        cout << s[y] - s[x-1] << endl;
    }

}

int main(){
    test01();

    return 0;
}