#include <iostream>
#include <cstring>
using namespace std;
char arr[510];
int main(){
    double n = 0;
    cin >> n;
    int cnt = 0;
    cin >> arr;
    int len = strlen(arr);
    for(int i = 0;i < len;i++){
        char ch = 0;
        cin >> ch;
        if(ch == arr[i]) cnt++;
    }
    double res = cnt * 1.0/ len;
    if(res >= n) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}