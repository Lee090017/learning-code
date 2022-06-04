/*
 * @Author: your name
 * @Date: 2022-04-28 16:07:48
 * @LastEditTime: 2022-04-29 17:37:07
 * @LastEditors: Please set LastEditors
 * @Description: vector容器
 * @FilePath: \learningCode\project_05\vectorTest2.cpp
 */
#include<iostream>
#include<vector>
#include<string>

using namespace std;
//vector数据结构和数组十分类似也称为单端数组
//不同点在于数组是静态的不能拓展，vector可以动态扩展
//并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

//打印vector
// template <typename T>
void printVector(vector<int> &v){
    if(v.empty()){
        cout << "vector is empty" << endl;
        return;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * @brief 
 * 
 * vector的构造函数
 * 创建vector容器
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem); //构造函数将n个elem拷贝给本身。
vector(const vector &vec); //拷贝构造函数。

补充：
vector(n); //初始化vector，包含n个0元素
以下初始化也可以：
① vector<int> vector = {1,2,3,4};
② vector<int> vector{1,2,3,4};
③ vector<int> vector({1,2,3,4});
 * 
 */
void test01(){
    vector<int> v1;//默认构造
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    printVector(v1);

    //通过区间的方式构造
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    //n个element
    vector<int> v3(10,100);
    printVector(v3);

    //拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}

/**
 * @brief 
 * 
 * vector的赋值
 * 
 * 
vector& operator=(const vector &vec);//重载等号操作符
assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem); //将n个elem拷贝赋值给本身。
 * 
 */
void test02(){
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2 = v1;//operator==
    printVector(v1);

    vector<int> v3;
    v3.assign(v1.begin(),v1.end());//assign
    printVector(v3);

    vector<int> v4;
    v4.assign(10,100);//assign
    printVector(v4);

}

/**
 * @brief 
 * 
 * vector的容量和大小
 * 
 * 
empty(); //判断容器是否为空
capacity(); //容器的容量
size(); //返回容器中元素的个数
resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
​ //如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
​ //如果容器变短，则末尾超出容器长度的元素被删除
 * 
 */
void test03(){
    vector<int> v1;
    if(v1.empty()){
        cout << "v1 is empty" << endl;
    }
    v1.assign(10,100);

    cout << "capacity = " << v1.capacity() << endl;
    cout << "size = " << v1.size() << endl;

    v1.resize(5);//重新更改大小，删除多出的数据
    cout << "capacity = " << v1.capacity() << endl;
    cout << "size = " << v1.size() << endl;
    printVector(v1);

    v1.resize(7,5);//重新更改大小,用5填充默认位置
    cout << "capacity = " << v1.capacity() << endl;
    cout << "size = " << v1.size() << endl;
    printVector(v1);


}

/**
 * @brief 
 * 
 * vector的插入和删除
 * 
 * 
push_back(ele); //尾部插入元素ele
pop_back(); //删除最后一个元素
insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
erase(const_iterator pos); //删除迭代器指向的元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
clear(); //删除容器中所有元素
 * 
 */

void test04(){
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);//尾插
    }
    printVector(v1);

    v1.pop_back();//尾删

    vector<int>::iterator it = v1.begin();//

    v1.insert(it+3,2,100);//第一个参数是迭代器，在3的位置插入2个100
    printVector(v1);

    v1.erase(it+3);//删除3位置的元素
    printVector(v1);

    v1.erase(it+3,it+5);//删除3到5位置的元素
    printVector(v1);

    v1.clear();//清空
    printVector(v1);

}


/**
 * @brief 
 * 
 * vector的数据存取
 * 
 * 
at(int idx); //返回索引idx所指的数据
operator[]; //返回索引idx所指的数据
front(); //返回容器中第一个数据元素
back(); //返回容器中最后一个数据元素
 * 
 */

void test05(){
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);//尾插
    }

    int n1 = v1.at(5);
    cout << "n1: " << n1 << endl;

    int n2 = v1[1];
    cout << "n2: " << n2 << endl;

    int n3 = v1.front();
    cout << "n3: " << n3 << endl;

    int n4 = v1.back();
    cout << "n4: " << n4 << endl;
}

/**
 * @brief 
 * 
 * vector互换容器
 * 
 * 
swap(vec); // 将vec与本身的元素互换
 * 
 */

void test06(){
    vector<int> v1;
    // for(int i=0;i<10;i++){
    //     v1.push_back(i);//尾插
    // }
    // cout << "v1 capacity = " << v1.capacity() << endl;
    // cout << "v1 size = " << v1.size() << endl;

    // vector<int> v2;
    // for(int i=9;i>0;i--){
    //     v2.push_back(i);//尾插
    // }
    // cout << "v2 capacity = " << v2.capacity() << endl;
    // cout << "v2 size = " << v2.size() << endl;

    // v1.swap(v2);//交换了容器的数据
    // printVector(v1);
    // cout << "v1 capacity = " << v1.capacity() << endl;
    // cout << "v1 size = " << v1.size() << endl;
    // printVector(v2);
    // cout << "v2 capacity = " << v2.capacity() << endl;
    // cout << "v2 size = " << v2.size() << endl;

    //实际用途
    for(int i=0;i<100000;i++){
       v1.push_back(i);//尾插
    }
    cout << "v1 capacity = " << v1.capacity() << endl;
    cout << "v1 size = " << v1.size() << endl;

    v1.resize(3);
    cout << "v1 capacity = " << v1.capacity() << endl;
    cout << "v1 size = " << v1.size() << endl;//浪费空间

    vector<int>(v1).swap(v1);//匿名对象的大小为元素个数3，swap为容器的指针交换，匿名对象执行完后回收，不会占用空间
    cout << "v1 capacity = " << v1.capacity() << endl;
    cout << "v1 size = " << v1.size() << endl;

}

/**
 * @brief 
 * 
 * vector预留空间
 * 
 * 减少vector在动态扩展容量时的扩展次数
 * 
 * 
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
与resize不同，没有初始化
 * 
 */

void test07(){
    vector<int> v1;
    v1.reserve(100000);//一次开辟足够的空间
    int num = 0;//初始容量
    int count = 0;//扩容次数
    for(int i=0;i<100000;i++){
       v1.push_back(i);//尾插
       if(num != v1.capacity()){//发生扩容
            num = v1.capacity();
            count++;
       }
    }
    cout << "count: " << count << endl;//18次开辟空间 --->  1次
}

int main(){
    test07();

    return 0;
}
