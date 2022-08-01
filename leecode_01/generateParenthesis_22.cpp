/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-03 12:14:25
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-03 12:56:45
 * @FilePath: \learningCode\leecode_01\cc.cpp
 * @Description: 22.括号生成
 */
#include<iostream>
#include<vector>
#include<set>
#include<iostream>
#include<string>
using namespace std;

vector<string> s;

//深度遍历
void dp(string str,int n,int i,int j){//str 当前的字符， n 总字符， i 已入栈的 (，j 已入栈的 )
    if(i == n && j == n){
        s.push_back(str);//将组合添加到集合
        return;
    }else{
        if(i < n){//"("随时可以入栈
            dp(str + "(", n, i+1, j);
        }
        if(j < i){//小于已入栈的"("个数才能入栈
            dp(str + ")", n, i, j+1);
        }
    }
}

//生成所有括号组合
vector<string> generateParenthesis(int n) {//n表示几对括号
    string str = "";
    dp(str,n,0,0);
    vector<string> res(s.begin(),s.end());
    return res;
}

void printVector(const vector<string>& s){
    if(s.empty()){
        cout << "set is empty" << endl;
        return;
    }
    for(vector<string>::const_iterator i = s.begin(); i != s.end(); i++){
        cout << (*i) << " , ";
    }
    cout << endl;
}


int main(){
    vector<string> v = generateParenthesis(4);
    cout << v.size() << endl;

    printVector(v);
    return 0;
}