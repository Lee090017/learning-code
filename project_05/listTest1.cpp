/*
 * @Author: your name
 * @Date: 2022-04-29 16:01:37
 * @LastEditTime: 2022-04-29 17:34:51
 * @LastEditors: Please set LastEditors
 * @Description: list链表
 * @FilePath: \learningCode\project_05\listTest1.cpp
 */

/**
 * @brief 
 * 
 * 链表由节点构成 节点由指针域和数组域构成
 * 
 * 优点： 链表可以对任意位置进行快速插入和删除
 * 缺点： 遍历速度没有数组快
 *       占用空间比数组大
 * 
 * 
 * STL中的链表是一个双向循环链表  data prev next
 * 
 * 由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器
 * 
 * List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。
 */


#include<iostream>
#include<string>
#include<list>
using namespace std;

void printList(const list<int>& l){
    if(l.empty()){
        cout << "list is empty" << endl;
        return;
    }
    for(list<int>::const_iterator it = l.begin(); it != l.end();it++){
        cout << *it <<" ";
    }
    cout << endl;
}

/**
 * @brief 
 * 
 * list构造函数
 * 
list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
list(beg,end); //构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem); //构造函数将n个elem拷贝给本身。
list(const list &lst); //拷贝构造函数。

补充：
list(n); //初始化list，包含n个0元素
以下初始化也可以：
① list<int> list = {1,2,3,4};
② list<int> list{1,2,3,4};
③ list<int> list({1,2,3,4});


 */

void test01(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    printList(l1);

    list<int> l2(l1.begin(),l1.end());
    printList(l2);

    list<int> l3(l2);
    printList(l3);

    list<int> l4(10,100);
    printList(l4);
}


/**
 * @brief 
 * 
 * list赋值和交换操作
 * 
assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem); //将n个elem拷贝赋值给本身。
list& operator=(const list &lst); //重载等号操作符
swap(lst); //将lst与本身的元素互换。
 */

void test02(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);

    list<int> l2;
    l2.assign(l1.begin(), l1.end());
    printList(l2);

    list<int> l3;
    l3.assign(10,100);
    printList(l3);

    list<int> l4;
    l4 = l3;
    printList(l4);

    l2.swap(l4);
    printList(l2);
    printList(l4);
    cout << "l4 size = " << l4.size() << endl;


}

/**
 * @brief 
 * 
 * list大小操作
 * 
size(); //返回容器中元素的个数
empty(); //判断容器是否为空
resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
​ //如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
 */

void test03(){
    list<int> l1;
    printList(l1);
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);

    cout << "l1 size = " << l1.size() << endl;

    l1.resize(10,88);//调整大小为10，默认填充88
    printList(l1);


}

/**
 * @brief 
 * 
 * list插入和删除
 * 
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(const_iterator pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(const_iterator pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(const_iterator pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。  可以插入数组区间
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(const_iterator pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。
 */

void test04(){
    list<int> l1;
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    printList(l1);

    l1.pop_back();
    l1.pop_front();
    printList(l1);

    list<int>::iterator it = l1.begin();
    l1.insert(it,1);
    printList(l1);//迭代器依然指向原来数据的位置

    l1.insert(it,2,100);
    printList(l1);

    l1.erase(it);//删除2
    printList(l1);

    l1.remove(100);//删除所有100
    printList(l1);
}

/**
 * @brief 
 * 
 * list数据存取
 * 
 * 没有at和[]，因为其本质是链表，不是连续的线性空间，迭代器不支持随机访问
front(); //返回第一个元素。
back(); //返回最后一个元素。
 */

void test05(){
    list<int> l1;
    for(int i=0;i<11;i++){
        l1.push_back(i);
    }

    cout << "l1 front = " << l1.front() << endl;
    cout << "l1 back = " << l1.back() << endl;

    //验证迭代器不支持随机访问
    list<int>::iterator it = l1.begin();
    it--;//支持双向操作

    cout << &(*it) << endl;
    cout << &(*(l1.end())) << endl;
    it++;
    // it = it + 1;
    // it = it + 1;//错误，不支持随机访问


}

/**
 * @brief 
 * 
 * list反转和排序
 * 
reverse(); //反转链表
sort(); //链表排序
 */

//降序
bool myCompare(int a,int b){
    //降序 第一个数 > 第二个数
    return a>b;
}

void test06(){
    list<int> l1;
    for(int i=0;i<11;i++){
        l1.push_back(i);
    }

    l1.reverse();//反转
    printList(l1);

    // sort(l1.begin(),l1.end());//所有不支持随机访问迭代器的容器，不可以用标准的算法
    //不支持随机访问迭代器的容器，内部提供成员函数排序
    l1.sort();//排序，默认升序
    printList(l1);

    l1.sort(myCompare);//降序

    printList(l1);

}

/**
 * @brief 
 * 
 * list的其他接口
 * 
 * unique 去重
 * merge 以升序合并两个排序的列表

 */

void test07(){
    list<int> l1;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(3);
    l1.push_back(3);
    l1.push_back(3);
    l1.push_back(5);
    l1.unique();
    printList(l1);

    list<int> l2;
    l2.push_back(2);
    l2.push_back(4);
    l2.push_back(6);

    l1.merge(l2);//合并两个排序链表
    printList(l1);

}


int main(){

    test07();


    return 0;
}