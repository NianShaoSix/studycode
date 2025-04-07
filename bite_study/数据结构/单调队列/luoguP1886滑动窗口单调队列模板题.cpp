//https://www.luogu.com.cn/problem/P1886
#include <iostream>
#include <deque>

using namespace std;
const int N = 1e6 + 10;
int n,k;
int a[N];
int mi[N],ma[N];
deque<int> q1,q2;
int main(){
    cin >> n >>k;
    
    for(int  i = 1;i <= n;i++){
        cin >> a[i]; 
    }

    for(int i = 1;i <= n;i++){
        //求窗口内最大值
        while(q1.size()&&a[q1.back()] <= a[i]) q1.pop_back();
        q1.push_back(i);
        if(q1.back() - q1.front() + 1 > k) q1.pop_front();
        
        ma[i] = q1.front();

        //求窗口内最小值
        while(q2.size()&&a[q2.back()] >= a[i])  q2.pop_back();
        q2.push_back(i);
        if(q2.back() - q2.front() + 1 > k) q2.pop_front();
        
        mi[i] = q2.front();
    }
    for(int i = k;i <= n;i++){
        cout << a[mi[i]] <<" ";
    }
    puts("");
    for(int i = k;i <= n;i++){
        cout <<a[ma[i]] <<" ";
    }
    return 0;
}