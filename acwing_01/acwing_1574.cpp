/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-09 13:37:03
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-09 17:23:33
 * @FilePath: \learningCode\acwing_01\acwing_1574.cpp
 * @Description: 接雨水
 */

/*
10
0 10 4 6 5 0 9 8 10 2

28

5
4 2 1 0 3
*/
# include <iostream>
# include <stack>

using namespace std;

const int N = 100010;
int a[N];

int main(){
    int n, res = 0;
    cin >> n;
    for (int i=0; i<n ; i++) cin >> a[i];//输入元素

    stack<int> st;//存数的下标
    for (int i=0; i<n; i++){
        while(!st.empty() && a[st.top()] < a[i]){
            //出栈
            int t = st.top();
            st.pop();
            if (!st.empty()){
                int l = i - st.top() - 1;
                int h = min(a[i], a[st.top()]) - a[t];
                res += l * h;
            }
        }
        st.push(i);
    }
    cout << res << endl;
    return 0;
}