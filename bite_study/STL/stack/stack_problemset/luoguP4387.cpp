#include <iostream>
#include <stack>
const int N = 1e6 + 10;
using namespace std;
int a[N],mo[N];
int q,n;
int main(){
    cin >> q;
    while(q--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        for(int i =1;i<=n;i++){
            cin >> mo[i];
        }
        stack<int> st;
        int j = 1;
        for(int i = 1;i <=n;i++){
            st.push(a[i]);
            while(j <= n &&st.size()&&st.top()==mo[j]){
                st.pop();
                j++;
            }
            
        }
        if(st.size()) cout <<"No"<<endl;
        else cout <<"Yes"<<endl;
    }
    return 0;
}