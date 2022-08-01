/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-03 11:13:05
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-03 12:12:23
 * @FilePath: \learningCode\leecode_01\nextSort_31.cpp
 * @Description: 31.下一个排列
 */
#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

void swap(vector<int> &nums,int i,int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void nextPermutation(vector<int> &nums){
    int i,j;//双指针
    i = nums.size() - 1;
    j = nums.size() - 1;
    //两次扫描
    while(i-1 >= 0 && nums[i-1] >= nums[i]) i--;
    cout << i << endl;
    //判断全为降序，表示当前数组已为最大值
    if(i == 0) return;
    while(j > i-1 && nums[j] <= nums[i-1]) j--;
    cout << j << endl;
    swap(nums,i-1,j);
    //翻转降序序列
    vector<int>::iterator it_b,it_e;
    it_b = nums.begin()+i;
    it_e = nums.end();
    reverse(it_b,it_e);
} 

void myPrint(int n){
    cout << n << " ";
}

int main(){
    vector<int> nums = {5,1,1};

    nextPermutation(nums);

    for_each(nums.begin(), nums.end(), myPrint);

    return 0;
}