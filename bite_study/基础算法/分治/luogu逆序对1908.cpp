//https://www.luogu.com.cn/problem/P1908
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

const int N = 5e5+10;
LL a[N],temp[N];
int n;

LL merge(int left,int right){
    if(left >= right) return 0;
    LL ret = 0;
    int mid = (left+right)>>1;
    ret+=merge(left,mid);
    ret+=merge(mid+1,right);
    //一左一右
    int cur1 = left,cur2 = mid + 1,i = left;
    while(cur1<=mid&&cur2<=right){
        if(a[cur1]<=a[cur2]) temp[i++]=a[cur1++];
        else{
            ret+=mid+1-cur1;
            temp[i++] = a[cur2++];
        }
    }
    while(cur1 <= mid) temp[i++] = a[cur1++];
    while(cur2 <= right) temp[i++] = a[cur2++];
    for(int j = left; j <= right;j++) a[j] = temp[j];
    return ret;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    cout <<merge(1,n)<<endl;

    return 0;
}