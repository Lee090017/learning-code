#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>//算数生成算法属于小型算法，使用时需要包含该头文件
using namespace std;

//1.常见的算法生成算法
// accumulate // 计算容器元素累计总和
// fill // 向容器中添加元素

/*
accumulate(iterator beg, iterator end, value);
// 计算容器元素累计总和
// beg 开始迭代器
// end 结束迭代器
// value 起始值
*/

void test01(){
    vector<int> v;
    int sum = 0;
    for(int i=0; i<10;i++){
        v.push_back(i);
        sum += i;
    }

    int total = accumulate(v.begin(), v.end(),0);//参数三为起始累加值 sum = 0

    cout << total << endl;
    cout << sum << endl;

}

/*
fill(iterator beg, iterator end, value);
// 向容器中填充元素
// beg 开始迭代器
// end 结束迭代器
// value 填充的值
*/

void PrintNum01(int a){
    cout << a << " ";
}

void test02(){
    vector<int> v;
    v.resize(10);

    //后期重新填充
    fill(v.begin(), v.end(),100);

    for_each(v.begin(), v.end(), PrintNum01);
    cout << endl;

}


//2.常见的集合算法
// set_intersection // 求两个容器的交集
// set_union // 求两个容器的并集
// set_difference // 求两个容器的差集

/*
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的交集
// 注意:两个集合必须是有序序列

// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器
*/

void test03(){
    vector<int> v1 = {1,2,3,4,5,6,7};
    vector<int> v2 = {5,6,7,8,9,10};

    vector<int> target;

    int s1 = v1.size();
    int s2 = v2.size();
    target.resize(min(s1,s2));//min 获取更小数

    // set_intersection(v1.begin(), v1.end(),v2.begin(), v2.end(),target.begin());//5 6 7 0 0 0
    //使用返回值作为结束迭代器
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(),v2.begin(), v2.end(),target.begin());//5 6 7 

    for_each(target.begin(), itEnd, PrintNum01);
    cout << endl;
}


/*
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的并集
// 注意:两个集合必须是有序序列

// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器

*/

void test04(){
    vector<int> v1 = {1,2,3,4,5,6,7};
    vector<int> v2 = {5,6,7,8,9,10};

    vector<int> target;

    int s1 = v1.size();
    int s2 = v2.size();
    target.resize(s1+s2);

    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(),v2.begin(), v2.end(),target.begin());//1 2 3 4 5 6 7 8 9 10 

    for_each(target.begin(), itEnd, PrintNum01);
    cout << endl;
}

/*
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

// 求两个集合的差集
// 注意:两个集合必须是有序序列

// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器
*/
void test05(){
    vector<int> v1 = {1,2,3,4,5,6,7};
    vector<int> v2 = {5,6,7,8,9,10};

    vector<int> target;

    int s1 = v1.size();
    int s2 = v2.size();
    target.resize(max(s1,s2));

    // v1有而v2没有的数 v1 - v1 n v2
    // vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(),v2.begin(), v2.end(),target.begin());//1 2 3 4 
    // v2有而v1没有的数 v2 - v1 n v2
    vector<int>::iterator itEnd = set_difference(v2.begin(), v2.end(),v1.begin(), v1.end(),target.begin());//8 9 10 

    for_each(target.begin(), itEnd, PrintNum01);
    cout << endl;
}

/*
unique（C++）函数的功能是元素去重。即”删除”序列中所有相邻的重复元素(只保留一个)。 需要满足序列为有序序列

a 这里的删除不是真的delete，而是将重复的元素放到容器末尾
b unique函数的返回值是去重之后的尾地址
c 一定要先对数组进行排序才可以使用unique函数
*/

void test06(){
    int arr[10] = {1,8,5,4,2,6,6,8,1,3};
    sort(arr,arr+10);

    int len;
    len = unique(arr,arr+10) - arr;//去重之后的长度

    for(int i=0; i<10; i++){
        cout << arr[i] << endl;//将重复元素放到末尾
    }

}


int main(){

    test06();

    return 0;
}