//https://ac.nowcoder.com/acm/problem/207040
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int a[N];
int ret;int sum;
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    int left = 1,right = 1;int len = 0;
    while(right <= n){
        len+=a[right];
        while(len > sum/2){
            len-=a[left];
            left++;
        }
        ret =max(len,ret);
        right++;
    }
    cout << ret << endl;
    return 0;
}