#include <iostream>
#include <string>
using namespace std;
int n;
string name;
float t;
int k;
int cnt;
int main(){
    cin >> n;
    while(n--){
        cin >> name >> t >> k;
        if(t >= 37.5 && k == 1){
            cout << name << endl;
            cnt++;
        }
    }
    cout << cnt <<endl;
}