/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-05 15:48:19
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-05 17:04:43
 * @FilePath: \learningCode\project_08\list.cpp
 * @Description: （1）链表 单链表
 */
#include<iostream>

using namespace std;

/*
一、动态链表的创建方式
① 
struct Node{
    int val;
    Node *next;
};

new Node();非常慢，笔试易超时

② 单链表（邻接表 存 图 和 树）
原理：使用两个数组进行关联
head -> 3 -> 5 -> 7 -> 9 -> null
        0    1    2    3     -1
e[0] = 3    e[1] = 5    e[2] = 7    e[2] = 9
ne[0] = 1   ne[1] = 2   ne[2] = 3   ne[2] = -1

③ 双链表 （优化问题）

*/

const int N = 100010;

//头节点下标 值 next指针 当前节点的指针
int head,e[N],ne[N],idx;

//将x插入到头节点
void add_to_head(int x){
    e[idx] = x;//将值赋给 新节点idx 
    ne[idx] = head;//将当前插入节点 idx 指向 head指向的值
    head = idx;//头指针指向新的节点
    idx++;//idx指针后移
}

//将x点插入到下标k的后面
void add(int k,int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

//将下标k点后面的点删除
void remove(int k){
    if(k == 0) head = ne[head];//当k为0时删除头节点
    ne[k-1] = ne[ne[k-1]];
}

//打印当前链表
void printList(){
    int t = head;
    while (t != -1)
    {
        cout << e[t] << " ";
        t = ne[t];
    }
    cout << endl;
}

//单链表的操作
void test01(){
    //链表初始化
    head = -1;
    idx = 0;

    //输入指令实现单链表的插入和删除
    int m;
    cin >> m;

    char c;
    int k,x;
    for(int i = 0; i < m; i++){
        cin >> c;
        if(c == 'H'){//向链表头插入x
            cin >> x;
            add_to_head(x);
            // printList();
        }else if(c == 'D'){//删除第k个插入的数后面的数
            cin >> k; 
            remove(k);
            // printList();
        }else if(c == 'I'){//在第k个插入数后面插入数字x
            cin >> k >> x;
            add(k-1,x);
            // printList();
        }
    }

    //输出链表
    printList();
    

}

int main(){
    test01();

    return 0;    
}