//离散化模板二：排序 + 哈希表去重以及记录最终的位置
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 10;

int n;int a[N];
int pos;
int disc[N];//帮助离散化
unordered_map<int,int>id;//<原始的值，离散之后的值>


int main(){
    cin >>n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        disc[++pos] = a[i];
    }
    //离散化
    sort(a+1,a+1+n);//排序
    int cnt = 0;//标记当前值是第几号元素
    for(int i = 1;i <= pos;i++){
        int  x = disc[i];
        if(id.count(x)) continue;
        id[x] = ++cnt;
    }

    for(int i = 1;i <= n;i++){
        cout << a[i] <<"离散化之后："<<id[a[i]]<<endl;
    }

    return 0;

}