/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-07 15:28:57
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-07 16:04:24
 * @FilePath: \learningCode\project_08\doubleList.cpp
 * @Description: （1）链表 双链表
 */
#include<iostream>

using namespace std;

const int N = 100010;

int m;
int e[N],l[N],r[N],idx;

//初始化
void init(){
    // 0 表示左端点 1表示右端点
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

//在第k个点的右边插入x
void add(int k,int x){
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    r[k] = idx;
    l[r[idx]] = idx;
    idx++;
}

//删除第k个点
void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

//打印双链表
void printDoubleList(){
    int i = 0;
    while(r[i] != 1){
        i = r[i];
        cout << e[i] << " ";
    }
    cout << endl;
}

/*
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2

8 7 7 3 2 9
*/

int main(){

    cin >> m;
    string c;
    int k,x;
    init();//初始化
    while (m--)
    {
        cin >> c;
        if(c == "L"){//链表的最左端插入
            cin >> x;
            add(0,x);//0节点右插入
        }else if(c == "R"){
            cin >> x;
            add(l[1],x);//1节点左插入
        }else if(c == "D"){
            cin >> k;
            remove(k+1);
        }else if(c == "IL"){
            cin >> k >> x;
            add(l[k+1],x);
        }else if(c == "IR"){
            cin >> k >> x;
            add(k+1,x);
        }
        printDoubleList();
        
    }
    


    return 0;
}