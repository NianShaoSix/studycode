//离散化模板1：排序 + 去重 + 二分查找离散之后的结果
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;int a[N];
int pos;
int disc[N];//帮助离散化

int find(int x){
    int l = 1,r = pos;
    while(l < r){
        int mid = (l + r)/2;
        if(disc[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
    cin >>n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        disc[++pos] = a[i];
    }
    //离散化
    sort(a+1,a+1+n);//排序
    pos = unique(disc + 1,disc + 1 + pos) -(disc + 1);//去重

    for(int i = 1;i <= n;i++){
        cout << a[i] <<"离散化之后："<<find(a[i])<<endl;
    }

    return 0;

}