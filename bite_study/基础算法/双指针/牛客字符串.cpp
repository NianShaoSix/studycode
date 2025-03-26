//https://ac.nowcoder.com/acm/problem/18386
#include <iostream>

using namespace std;
const int N = 1e6+10;
int a[N];
int kind,mp[27];

int main(){
    char ch;int sz = 1;
    while(cin >> ch){
    
        a[sz++] = (ch-'a' + 1);
        
    }
    int left = 1,right = 1,len = sz ;
    while(right < sz){
        mp[a[right]]++;
        if(mp[a[right]]==1) kind++;
        while(kind == 26){
            len = min(right - left + 1,len);
            mp[a[left]]--;
            if(mp[a[left]]==0) kind--;
            left++;   
        }
        right++;
    }
    cout << len <<endl;
    return 0;
}