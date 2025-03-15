// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;
// stack<char> st1,st2;
// int main(){
//     char ch;
//     while(cin >> ch ){
//         if(ch == '('||ch == '['){
//             st1.push(ch);
//         }
//         else {
//             int left = st1.top();
//             if(ch ==')'&&left != '('){
//                 st2.push('(');
//                 st2.push(')');
//             } 
//             else if(ch == ']'&&left!='['){
//                 st2.push('[');
//                 st2.push(']');
//             }
//             else if(ch == ')'&&left == '('){
//                 st2.push('(');
//                 st2.push(')');
//                 st1.pop();
//             }
//             else{
//                 st2.push('[');
//                 st2.push(']');
//                 st1.pop();
//             }
//         }
//         while(st1.size()){
//             if(st1.top() =='('){
//                 st2.push('(');
//                 st2.push(')');
//                 st1.pop();
//             }
//             else{
//                 st2.push('[');
//                 st2.push(']');
//                 st1.pop();
//             }
//         }
//     }
//     while(st2.size()){
//         cout <<st2.top();
//         st2.pop();
//     }

//     return 0;
// }

#include <iostream>
#include <stack>
#include <string>
const int N = 110;
using namespace std;
int st[N];//标记是否能匹配;
string s;
int main(){
    cin >> s;
    stack<int>stk;//标记左括号的位置
    for(int i = 0;i < s.size();i++){
        if(s[i]=='('||s[i]=='['){
            stk.push(i);
        }
        else{
            if(stk.empty()) continue;//?
            char ch = s[stk.top()];
            if(s[i]==')'&&ch =='('||s[i]==']'&&ch=='[') {
                st[i] = st[stk.top()]=1;
                stk.pop();
            }
        }
    } 
    string r ="";
    for(int i = 0;i < s.size();i++){
        int ch = s[i];
        if(st[i]) r+=s[i];
        else{
         if(s[i]=='('||s[i]==')'){
            r+='(';
            r+=')';
        }
        else if(s[i]=='['||s[i]==']'){
            r+='[';
            r+=']';
        }
    }}
    cout << r <<endl;
    return 0;
}
