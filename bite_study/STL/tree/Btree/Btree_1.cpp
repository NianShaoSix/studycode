//二叉树的链式存储
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int l[N],r[N],e[N];
int n;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> l[i] >> r[i]; 
    }
    return 0;
}