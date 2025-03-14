// #include <bits/stdc++.h>
// using namespace std;
// int n,m;
// bool vis[101];
// int a[101];
// int b[101];
// int main(){
//     cin >> n >> m;
//     for(int i=1;i<=n;i++){
//         vis[i] = false; //初始化所有人都未出来
//         a[i]=i;
//         b[i]=0;
//     }
//     vis[0]=true;
//     int j=0;int k = 0;
//     int count=0;
//     while (count < n){
//         for(int j=1;count<n;j++){//每次遍历一遍数组
//               j=j%(n+1);
//             if(vis[j]==false){
//                 k++;
//             }
//             if(k==m){
//                 vis[j]=true;
//                 count ++;
//                 b[count]=a[j];
//                 k=0;
//             }
//         }
      
//     }
//     for(int i=1;i<=n;i++){
//         cout<<b[i]<<" ";
//     }
//     return 0;
// }
#include <iostream>
using namespace std;
const int N = 110;
int n,m;
int ne[N],t;
int main(){
    cin >> n >>m;
    for(int i = 1;i < n;i++){
        ne[i] = i + 1;
    }
    ne[n] = 1;
    //模拟约瑟夫问题
    int t = n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < m;j++){
            t = ne[t];
        }
        cout << ne[t] <<' ';
        ne[t] = ne[ne[t]];
    }
    return 0;
}