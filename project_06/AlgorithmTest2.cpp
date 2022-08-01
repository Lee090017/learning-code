/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-06-20 18:32:54
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-06-23 22:17:19
 * @FilePath: \learningCode\project_06\AlgorithmTest2.cpp
 * @Description: 常见的排序算法、拷贝和替换算法
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>//使用内建函数需要添加此头文件
#include<ctime>
using namespace std;

/*1.常见的排序算法
sort //对容器内元素进行排序
random_shuffle //洗牌 指定范围内的元素随机调整次序
merge // 容器元素合并，并存储到另一容器中
reverse // 反转指定范围的元素
*/

/*
sort(iterator beg, iterator end, _Pred);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// _Pred 谓词
*/
bool CompareNum01(int a,int b){
    return a > b;//降序排列
}

void PrintNum01(int n){
    cout << n << endl;
}

void test01(){
    vector<int> v = {1,3,5,7,6,4,2,0};

    // sort(v.begin(),v.end(), CompareNum01);

    //内建函数对象
    sort(v.begin(),v.end(), greater<int>());

    for_each(v.begin(),v.end(),PrintNum01);
}

/*
random_shuffle(iterator beg, iterator end);
// 指定范围内的元素随机调整次序
// beg 开始迭代器
// end 结束迭代器
*/

void test02(){
    srand((unsigned int)time(NULL));//随机数种子

    vector<int> v = {1,2,3,4,5,6,7,8,9,10};//打乱顺序

    random_shuffle(v.begin(), v.end());

    for_each(v.begin(), v.end(), PrintNum01);
}

/*
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 容器元素合并，并存储到另一容器中，输出也是有序序列
// 注意: 两个容器必须是有序的
// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器
*/

void test03(){
    vector<int> v1 = {1,3,5,7,9};
    vector<int> v2 = {2,4,6,8,10};
    vector<int> target;

    target.resize(v1.size()+v2.size());//需要提前分配空间

    merge(v1.begin(), v1.end(),v2.begin(),v2.end(),target.begin());

    for_each(target.begin(), target.end(), PrintNum01);
}

/*
reverse(iterator beg, iterator end);
// 反转指定范围的元素
// beg 开始迭代器
// end 结束迭代器
*/

void test04(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    reverse(v.begin(), v.end());

    for_each(v.begin(), v.end(), PrintNum01);
}

/*2.常用的拷贝和替换算法
copy // 容器内指定范围的元素拷贝到另一容器中
replace // 将容器内指定范围的旧元素修改为新元素
replace_if // 容器内指定范围满足条件的元素替换为新元素
swap // 互换两个容器的元素
*/

/*
copy(iterator beg, iterator end, iterator dest);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// dest 目标起始迭代器
*/

void test05(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    vector<int> target;

    target.resize(v.size());//提前开辟空间

    copy(v.begin(), v.end(), target.begin());

    for_each(target.begin(), target.end(), PrintNum01);
}

/*
replace(iterator beg, iterator end, oldvalue, newvalue);
// 将区间内的旧元素 替换成 新元素
// beg 开始迭代器
// end 结束迭代器
// oldvalue 旧元素
// newvalue 新元素
*/
void test06(){
    vector<int> v = {1,2,3,4,5,5,7,8,9,10};
    replace(v.begin(), v.end(),5,0);//将其中的5变为0

    for_each(v.begin(), v.end(), PrintNum01);
}

/*
replace_if(iterator beg, iterator end, _pred, newvalue);
// 按条件替换元素，满足条件的替换成指定元素
// beg 开始迭代器
// end 结束迭代器
// _pred 谓词
// newvalue 替换的新元素
*/

bool ReplaceOver5(int n){
    return n > 5;
}

void test07(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    replace_if(v.begin(), v.end(),ReplaceOver5,0);//将其中大于5的数变为0

    for_each(v.begin(), v.end(), PrintNum01);
}

/*
swap(container c1, container c2);
// 互换两个容器的元素
// c1容器1
// c2容器2
*/

void test08(){
    vector<int> v1 = {1,2,3,4,5,6,7};
    vector<int> v2 = {8,9,10};

    swap(v1,v2);

    for_each(v1.begin(), v1.end(), PrintNum01);
    cout << "size of v1 is " << v1.size() << endl;
    cout << "capacity of v1 is " << v1.capacity() << endl;
    for_each(v2.begin(), v2.end(), PrintNum01);
    cout << "size of v2 is " << v2.size() << endl;
    cout << "capacity of v2 is " << v2.capacity() << endl;
}

int main(){
    test08();
    

    return 0;
}