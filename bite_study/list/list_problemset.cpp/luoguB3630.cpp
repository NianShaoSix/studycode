#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int e[N],ne[N];
int n;int h;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        e[i] = i;
        cin >> ne[i];
        }
    cin >> h;
    cout << e[h] << ' ';
    for(int i = ne[h]; i ;i = ne[i]){
        cout << e[i] << ' ';
    }
    return 0;
}