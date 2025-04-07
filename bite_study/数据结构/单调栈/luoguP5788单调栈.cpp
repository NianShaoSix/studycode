//https://www.luogu.com.cn/problem/P5788
#include <iostream>
#include <stack>
using namespace std;

const int N = 3e6 +10;
int a[N];int n;
int f[N];
void s(){
    stack<int> st;
    for(int i = n;i >= 1;i--){
        while(st.size()&&a[st.top()]<=a[i]) st.pop();
        if(st.size()) f[i] = st.top();
        st.push(i);
    }
}
int main(){
    
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >>a[i];
    }
    s();
    for(int i = 1; i <= n;i++)
    {
        cout <<f[i]<<" ";
    }
    return 0;
}