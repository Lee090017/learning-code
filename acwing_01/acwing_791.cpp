/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-04 14:35:45
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 14:38:05
 * @FilePath: \learningCode\acwing_01\acwing_791.cpp
 * @Description: 高精度加法
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> sum(vector<int>& A, vector<int>& B){
    vector<int> C;
    int t = 0;//下一位的进位
    for(int i=0; i < A.size() || i < B.size(); i++){
        if(i < A.size()) t += A[i];//当前位相加
        if(i < B.size()) t += B[i];
        //得到个位和十位
        C.push_back(t%10);//保留个位
        t /= 10;//十位,参与下一次加减
    }
    //若总位数需要加1
    if(t) C.push_back(t);//将进位给最高位

    return C;
}

int main(){

    string a,b;
    cin >> a;
    cin >> b;

    vector<int> A;
    vector<int> B;

    for(int i=a.size()-1; i >= 0; i--) A.push_back(a[i]-'0');//从低位到高位依次放入vector容器
    for(int i=b.size()-1; i >= 0; i--) B.push_back(b[i]-'0');//从低位到高位依次放入vector容器

    auto v = sum(A,B);

    for(int i=v.size()-1; i>=0; i--){
        cout << v[i];
    }
    cout << endl;

    return 0;
}