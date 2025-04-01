#include <iostream>
using namespace std;
const int N = 300;
int n;
char root;
char l[N],r[N];
//先序遍历
void dfs(char ch){
    cout << ch; 
    if(l[ch]!='*') dfs(l[ch]);
    if(r[ch]!='*') dfs(r[ch]);
}

int main(){
    cin >> n;
    cin >> root;
    cin >> l[root] >> r[root];
    for(int i = 2;i <= n;i++){
        char t; cin >> t;
        cin >> l[t] >> r[t];
    }
    dfs(root);
    return 0;
}