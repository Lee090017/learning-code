/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-04 14:35:45
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 14:55:11
 * @FilePath: \learningCode\acwing_01\acwing_791.cpp
 * @Description: 高精度减法
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> sub(vector<int>& A, vector<int>& B){
    vector<int> C;
    int t = 0;//上一位的借位
    for(int i = 0; i < A.size();i++){   
        t = A[i] - t;//减去借位后的位数
        if(i < B.size()) t -= B[i];//与B做差
        C.push_back((t+10)%10);//忽略正负的影响
        if(t < 0) t = 1;//需要继续借位
        else t = 0;
    }
    while(C.size()>1 && C.back() == 0) C.pop_back();//删除高位上无用的0，但保证至少留一个数为0
    return C;
}

int main(){

    string a,b;
    cin >> a;
    cin >> b;

    //比较a,b大小
    if(a.size() > b.size()) {//a > b
        
    }else if(a.size() == b.size()){//长度相等
        int s = a.size();
        for(int i=0; i<s; i++){
            if(a[i] < b[i]){
                swap(a,b);//a < b
                cout << "-";
                break;
            }else if(a[i] > b[i]) break;
            else continue;
        }
    }else{ //a < b
        cout << "-";
        swap(a,b);
    }

    vector<int> A;
    vector<int> B;

    for(int i=a.size()-1; i >= 0; i--) A.push_back(a[i]-'0');//从低位到高位依次放入vector容器
    for(int i=b.size()-1; i >= 0; i--) B.push_back(b[i]-'0');//从低位到高位依次放入vector容器

    auto v = sub(A,B);

    for(int i=v.size()-1; i>=0; i--){
        cout << v[i];
    }
    cout << endl;

    return 0;
}