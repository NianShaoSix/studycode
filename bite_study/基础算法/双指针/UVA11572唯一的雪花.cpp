#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e6 + 10;
int a[N];


int main(){
    int T;cin >>T;
    while(T--){
        int n;cin >>n;
        for(int i = 1;i <=n;i++){
            cin >>a[i];
        }

        int left = 1,right = 1;
        unordered_map<int,int> mp;int ret = 0;
        while(right <=n){
                mp[a[right]]++;

            while(mp[a[right]] > 1){
                mp[a[left++]]--;
            }
            ret = max(ret,right - left+1);
            right++;
        }
        cout << ret <<endl;
    }
    return 0;
}