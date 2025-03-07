#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    bool flag = true;
    // cin >> s;
    // cout << s.size();
    while(cin >> s){
        if(flag) {
            cout <<s.size();
            flag = false;
        }
        else
        cout << ","<<s.size();
    }
    return 0;
}