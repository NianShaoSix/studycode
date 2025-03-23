#include <iostream>
#include <unordered_map>
#include <string>
const int N = 2e5 + 10;
using namespace std;
int n;
unordered_map<string,int> mp;
int cnt;
int main(){
    cin >> n;
    while(n--){
        string city,state,s1 ="",s2="";
        cin >> city >> state;
        s1=s1+city[0]+city[1];//city = city.substr(0,2);
        if(s1 == state) continue;
        cnt += mp[state + s1];
        s2=s1 + state;
        mp[s2]++;
        cout << s1 << endl;
    }
    cout << cnt << endl;
    return 0;
}