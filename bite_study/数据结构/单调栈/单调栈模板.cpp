//单调栈模板
//口诀：找左侧，正遍历，找右侧，逆遍历。
//      比它大，单调减，比他小，单调增。
#include <iostream>
#include <stack>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];
int ret[N];
stack<int> st;//存下标

//单调递减栈，用来找i号元素左边离他最近的比他大的数的位置
void test1(){
    // st.push(1);
    // ret[1] = 0;
    for(int i = 1; i <= n;i++){

       while(st.size()&&a[st.top()]<=a[i]) st.pop();
    //    if(st.size()) {
    //     ret[i] = st.top();
    //     st.push(i);
    //    }
    //    else {
    //     st.push(i);
    //     ret[i] = 0;
    //     }
        if(st.size()) ret[i] = st.top();
        st.push(i);
    }   
    
}
//单调递增栈，用来找i号元素左边离他最近的比他小的数的位置
void test2(){
    st.push(1);
    ret[1] = 0;
    for(int i = 2; i <= n;i++){

        while(st.size()&&a[st.top()]>=a[i]) st.pop();
        if(st.size()) {
         ret[i] = st.top();
         st.push(i);
        }
        else {
         st.push(i);
         ret[i] = 0;
         }
     }   
}
//单调递增栈，找右边离他最近的比他大的数
void test3(){
    st.push(n);
    ret[n] = 0;
    for(int i = n -1;i >= 1;i--){
        while(st.size()&&a[st.top()] <= a[i]) st.pop();
        if(st.size()){
            ret[i] = st.top();
            st.push(i);
        }
        else{
            ret[i] = 0;
            st.push(i);
        }
    }
}
//单调递减栈，找最右边离它最近的比他小的数
void test4(){
    st.push(n);
    ret[n] = 0;
    for(int i = n -1;i >= 1;i--){
        while(st.size()&&a[st.top()] >= a[i]) st.pop();
        if(st.size()){
            ret[i] = st.top();
            st.push(i);
        }
        else{
            ret[i] = 0;
            st.push(i);
        }
    }
}
void print(){
    for(int i = 1;i <= n;i++){
        cout <<ret[i]<<" ";
    }
    puts("");
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    // test1();
    // test2();
    // test3();
    test4();
    print();
    return 0;
}