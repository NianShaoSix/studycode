// #include <iostream>

// using namespace std;
// typedef long long LL;
// const int N = 1e5 + 10;
// LL n,m;
// LL a[N],b[N],c[N];
// LL f[N];
// LL s[N];
// LL ret;
// int main(){
//     cin >> n >> m;
//     for(int i = 1;i <= m;i++){
//         cin >> s[i];
//     }
//     for(int i = 1;i < m;i++){
//         int Max = max(s[i],s[i+1]);
//         int Min = min(s[i],s[i+1]);
//         f[Min]++;
//         f[Max]--;
//     }

//     for(int j = 1;j <n;j++){
//         cin >> a[j]>>b[j]>>c[j];
//     }

//     for(int i = 1;i <=n;i++){
//         f[i] = f[i]+f[i-1];
//         ret+=min(f[i]*a[i],c[i]+f[i]*b[i]);
//     }
//     cout<<ret <<endl;
//     return 0;
// }

#include <iostream>
using namespace std;
typedef long long LL;

const int N = 1e5 +10;

LL n,m;

LL f[N];
LL ret;
int main(){

    cin >> n >>m;//n个城市，n-1站，去m个城市
    int x;//第一站
    cin >> x;
    for(int  i = 2;i <= m;i++)
    {
        int y; cin >>y;//下一站
        if(x < y) f[x]++,f[y]--;
        else f[y]++,f[x]--;
        x = y;
    }

    for(int i = 1; i < n;i++) {
        f[i]+=f[i-1];
        int a,b,c;
        cin >> a>>b>>c;
        ret+=min(f[i]*a,c+b*f[i]);
    }
    cout << ret <<endl;
   
    return 0;
}
