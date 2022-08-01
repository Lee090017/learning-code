/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-02 15:38:08
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-02 17:27:38
 * @FilePath: \learningCode\project_07\highAccuracyCalculate.cpp
 * @Description: 高精度的加减乘除
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sum(vector<int>& A, vector<int>& B);//高精度加法 C = A + B, A >= 0, B >= 0
vector<int> sub(vector<int>& A, vector<int>& B);//高精度减法 C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> mul(vector<int> &A,int b);//高精度乘低精度 C = A * b, A >= 0, b >= 0
vector<int> div(vector<int> &A,int b);//高精度乘低精度 A / b = C ... r, A >= 0, b > 0

/*
高精度加法
数据范围：1~100000
*/

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

/*
高精度减法
*/
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

/*
高精度乘低精度
A 的长度 1-100000
b 为 0-10000
*/
vector<int> mul(vector<int> &A,int b){
    vector<int> C;
    int t = 0;//进位
    for(int i = 0; i < A.size() || t; i++){//只要进位不为0，i++
        if(i<A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    //由于b可能为0，因此需要消除高位为0的数
    while(C.size()>1 && C.back() == 0) C.pop_back();//删除高位上无用的0，但保证至少留一个数为0

    return C;
}

/*
高精度除以低精度
A 的长度 1-100000
b 为 1-10000
得到商C与余数r
*/
vector<int> div(vector<int> &A,int b,int &r){
    vector<int> C;
    r = 0;//开始余数为0
    for(int i = A.size()-1; i >= 0; i--){//从最高位开始计算
        r = r * 10 + A[i];//当前的除数为上一个余数进乘10（进了一位）加当前的个位A[i]
        C.push_back(r/b);//将整除数加入容器C
        r %= b;//下一位的余数
    }
    reverse(C.begin(),C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();//删除高位上无用的0，但保证至少留一个数为0

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

    // auto v = sum(A,B);
    // auto v = sub(A,B);
    // auto v = mul(A,1000);

    int r;
    auto v = div(A,6,r);

    cout << "C = ";
    for(int i=v.size()-1; i>=0; i--){
        cout << v[i];
    }
    cout << endl;
    cout << "r = " << r << endl;
    return 0;
}