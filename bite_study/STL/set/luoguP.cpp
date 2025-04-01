#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;
int n,p;
typedef long long LL;
map<string,int> mp;

bool check(char ch){
    if(islower(ch)||isupper(ch)||isdigit(ch))
    return true;
    else return false;
}


int main(){
    cin >> n >> p;
    for(int i = 0;i < n;i++){
        string s;int x;
        cin >> s >> x;
        mp[s] = x;
    }
    LL ret = 0;
    char ch ;
    string t = "";

    while(scanf("%c",&ch)!=EOF){
        if(check(ch)) t +=ch;
        else{
            ret = (ret + mp[t]) % p;
            t = "";
        }
    }

    cout << ret << endl;
    return 0;

}