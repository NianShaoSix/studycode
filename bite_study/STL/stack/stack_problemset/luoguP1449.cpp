#include <iostream>
#include <cctype>
#include <stack>
using namespace std;
stack<int> st;
int main(){
    char ch;int t= 0;
    while(cin >> ch){
        if(ch == '@') break;
        else if(isdigit(ch)) t = t * 10 + (ch - '0');
        else if(ch == '.') 
        {
            st.push(t);
            t = 0;
        }
        else if(ch == '+')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b + a);
        }
        else if(ch == '-')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b - a);
        }
        else if(ch =='*'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b * a);
        }
        else if(ch == '/'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b / a);
        }
    }
    cout << st.top() <<endl;
    return 0;
}