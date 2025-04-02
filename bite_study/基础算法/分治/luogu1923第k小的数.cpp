//https://www.luogu.com.cn/problem/P1923
#include <iostream>
#include <ctime>
using namespace std;

const int N = 5e6 + 10;
int a[N],temp[N];
int n,k;
int get_random(int left,int right){
    int pos = rand()%(right - left + 1)+left;
    return a[pos];
}
int quick_select(int left,int right,int k){
    if(left >= right) return a[left];
    //1. 选择基准元素
    int p = get_random(left,right);
    //2.数组分三块
    int l = left - 1, i = left,r = right + 1;
    while(i < r){
        if(a[i] < p) swap(a[++l],a[i++]);
        else if(a[i]==p) i++;
        else swap(a[i],a[--r]);
    }
    //3.选择存在最终结果的区间
    //[left,l] [l+1,r-1] [r,right]
    int a = l - left + 1, b = r - l -1,c = right - r + 1;
    if(k <= a) return quick_select(left,l,k);
    else if(k <= a + b) return p;
    else return quick_select(r,right,k-a-b);
}


int main(){
    //cin >> n>>k;
    scanf("%d%d",&n,&k);
    k++;
    srand(time(0));
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    cout <<quick_select(1,n,k)<<endl;;
    return 0;
}