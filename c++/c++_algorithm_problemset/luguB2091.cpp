#include <iostream>
using namespace std;
int n;
int a[1010];
int b[1010];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    int res = 0;
    for(int i = 1; i <= n;i++){
        res+= a[i]*b[i];
    }
    cout << res << endl;
}