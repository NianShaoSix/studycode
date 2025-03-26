#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n,m;int a[N];
int mp[N];int kind;
int main(){
    cin >> n>>m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int left = 1,right = 1;
    int begin = 1;int ret = n;
    while(right <= n){
         mp[a[right]]++;
        if(mp[a[right]]==1) kind++;
        while(kind == m){
            int len = right - left +1;
            if(len < ret){
            begin = left;
            ret = len;
            }
            // mp[a[left]]--;
            if(mp[a[left]]--==1) kind--;
            left++;
        }
        right++;
    }
    cout <<begin <<" "<<begin + ret-1<<endl;
    return 0;
}